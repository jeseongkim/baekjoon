typedef unsigned long long ull;
struct Binary_Matirx
{
	int nrows;
	int ncols;
	int Mbits;			// nrows + ncols
	int Midx;			// nrows + ncols - 1
	int nword;
	ull value[1000][32];
};
typedef struct Binary_Matirx my_mat;
my_mat tmat;


void Fill_row(my_mat *mptr, char bitstring[], int row);			// Func - (a)
int  GE1(my_mat *mptr, char inout[][1001], int pivot_clidx[]);	// Func - (b)
void Change_row(my_mat *mptr, int row1, int row2);				// Func - (d)
void Reduce_row(my_mat *mptr, int rank, int cridx);				// Func - (e)
void Fill_clidx_out_np(my_mat *mptr,int lidx,char inout[][1001], int rank);
void Fill_clidx_out_p(my_mat *mptr,int lidx,char inout[][1001], int rank, int ridxrow);

int n, m;

int main(int argc, char const *argv[])
{
	char inout[1000][1001];
	int Arank;

	// 1. insert row, col
	scanf("%d %d",&n, &m);

	// 2. Create n*(n+m) Matrix A||I
	my_mat AI = {n, m, n+m, n+m-1, ((n+m-1)/64)+1, 0, };
	my_mat *mptr = &AI;

	// 3. Fill each row
	for (int row = 0; row < n; ++row)
	{
		scanf("%s",inout[row]);
		Fill_row(mptr,inout[row], row);									// Func - (a)
	}
    
	int pivot_clidx[1000];
	// 4. For A|I, GE(RREF) until 1 ~ (m-1)th column (Lidx).
	// Morevoer, get Rank A and fill m-th col (Lidx) of out.
	Arank = GE1(mptr, inout, pivot_clidx);								// Func - (b)

	if (Arank == 0)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				inout[i][j]='+';
			}
			printf("%s\n",inout[i] );
		}
		return 0;
	}
	// 5. For j-th(1~m-1) column (Lidx), fill j-th col of out.(Lidx)
	// If j isn't pivot col, then rank can't decrease.
	// So, just show I's part and determine whether rank is inc or not.
	// If j is pivot col, 
	int trank = 0;
	for (int lidx = 0; lidx < m; ++lidx)
	{
		if (lidx == pivot_clidx[trank])
		{
			Fill_clidx_out_p(mptr,lidx, inout, Arank, trank);
			trank++;
		}
		else
		{
			Fill_clidx_out_np(mptr,lidx,inout, Arank);
		}
	}

	// 6. print out
	for (int row = 0; row < n; ++row)
		printf("%s\n",inout[row]);

	return 0;
}

void Fill_row(my_mat *mptr, char bitstring[], int row)
{
	int lidx,Lidx,ridx,Ridx;

	// Fill 1 ~ m -th col (Lidx)
	for (lidx = 0, ridx = mptr->Midx; lidx < m; ++lidx, --ridx )
	{
		mptr->value[row][ridx/64] *=2;
		if (bitstring[lidx]=='1')
			mptr->value[row][ridx/64]++;
	}

	// Set (m+ row+1 )-th col to 1 (Lidx)
	for (					; lidx < mptr->Mbits; ++lidx, --ridx )
	{
		mptr->value[row][ridx/64] *=2;
		if (lidx == (m+row))
			mptr->value[row][ridx/64]++;
	}
}

int  GE1(my_mat *mptr, char inout[][1001], int pivot_clidx[])
{
	int lidx, ridx, rank = 0;

	// 2. For 1 ~ (m)th col(Lidx), do GE
	for (lidx = 0, ridx = mptr->Midx; lidx < m; ++lidx, --ridx)
	{
		// GE : 1. Find pivot, 2. Change rank row and pivot row, 3. Reduce rank+1 ~ n row.
		for (int row = rank; row < n; ++row)
		{
			if ((mptr->value[row][ridx/64]>>(ridx%64))&1)
			{
				Change_row(mptr, rank, row);							// Func - (d)
				pivot_clidx[rank] = lidx;
				Reduce_row(mptr, rank++, ridx);						// Func - (e)
			}
		}

		if (rank == n)
			break;
	}

	return rank;
}


void Change_row(my_mat *mptr, int row1, int row2)				// Func - (d)
{
	if (row1 == row2)
	{
		return;
	}
	ull temp;
	for (int word = 0; word < mptr->nword; ++word)
	{
		temp = mptr->value[row1][word];
		mptr->value[row1][word] = mptr->value[row2][word];
		mptr->value[row2][word] = temp;
	}
}

void Reduce_row(my_mat *mptr, int rank, int cridx)				// Func - (e)
{
	for (int row = 0; row < n; ++row)
	{
		if (row == rank)
			continue;

		if ( ( mptr->value[row][cridx/64] >> (cridx%64) ) & 1 )
		{
			for (int word = 0; word < mptr->nword; ++word)
			{
				mptr->value[row][word] ^=mptr->value[rank][word];
			}
		}
	}
}

void Fill_clidx_out_np(my_mat *mptr,int lidx,char inout[][1001], int rank)
{
	int irankflag[1000]={0,}; // inc flag
	int ridx = mptr->Midx - lidx;
	int m_thbit, mi_thbit;
	for (int row = rank; row < n; ++row)
	{
		m_thbit = (mptr->value[row][ridx/64]>>(ridx%64))&1;
		for (int i = 0, ridx = n-1; i < n; ++i, --ridx)
		{
			mi_thbit = (mptr->value[row][ridx/64]>>(ridx%64))&1;
			if ((mi_thbit^m_thbit)==1)
			{
				irankflag[i] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (irankflag[i] == 1)
		{
			inout[i][lidx] = '+';
		}
		else{
			inout[i][lidx] = '0';
		}
	}
}

void Fill_clidx_out_p(my_mat *mptr,int lidx,char inout[][1001], int rank, int ridxrow)
{
	int uniqueness = 1;
	for (int mlidx = lidx+1, ridx = mptr->Midx-mlidx; mlidx < m; ++mlidx, --ridx)
	{
		if ( (mptr->value[ridxrow][ridx/64]>>(ridx%64))&1 )
		{
			uniqueness = 0;
			break;
		}
	}

	int m_thbit, mi_thbit;

	// Case 1) pivot, but exist another 1's in that row.
	if (uniqueness == 0)
	{
		int irankflag[1000] = {0,};
		for (int row = rank; row < n; ++row)
		{
			m_thbit = (mptr->value[row][(mptr->Mbits-lidx)/64]>>((mptr->Mbits-lidx)%64))&1;
			for (int i = 0, ridx = n-1; i < n; ++i, --ridx)
			{
				mi_thbit = (mptr->value[row][ridx/64]>>(ridx%64))&1;
				if ((mi_thbit^m_thbit) == 1)
				{
					irankflag[i] = 1;
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (irankflag[i] == 1)
			{
				inout[i][lidx] = '+';
			}
			else{
				inout[i][lidx] = '0';
			}
		}
	}
	else
	{
		//Case2) unique row col.
		int irankflag[1000] = {0,};
		int ridx = mptr->Midx-lidx;
		m_thbit = (mptr->value[ridxrow][ridx/64]>>(ridx%64))&1;
		for (int i = 0, ridx = n-1; i < n; ++i, --ridx)
		{
			mi_thbit = (mptr->value[ridxrow][ridx/64]>>(ridx%64))&1;
			if ((mi_thbit^m_thbit) == 1)
			{
				irankflag[i] = 1;
			}
		}

		for (int row = rank; row < n; ++row)
		{
			ridx = mptr->Midx-lidx;
			m_thbit = (mptr->value[row][(ridx)/64]>>((ridx)%64))&1;
			for (int i = 0, ridx = n-1; i < n; ++i, --ridx)
			{
				mi_thbit = (mptr->value[row][ridx/64]>>(ridx%64))&1;
				if ((mi_thbit^m_thbit) == 1)
				{
					irankflag[i] = 1;
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (irankflag[i] == 1)
			{
				inout[i][lidx] = '0';
			}
			else{
				inout[i][lidx] = '-';
			}
		}

	}

}