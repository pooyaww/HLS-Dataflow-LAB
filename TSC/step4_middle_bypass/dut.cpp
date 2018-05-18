
void bypass(int tmp1[128], int tmp2[128], int tmp3[128])
{
static int j;
  for(int i=0;i<128;i++)
    {
	  j++;
      tmp3[i] = tmp1[i] +tmp2[i];
    }  
}


void pass(int tmp2[128], int tmp4[128])
{
static int j;
  for(int i=0;i<128;i++)
    {
	  j++;
      tmp4[i] = tmp2[i];
    }
}

void double_pass(int a[128], int b[128], int tmp1[128], int tmp2[128])
{
static int j;
  for(int i=0;i<128;i++)
    {
	  j++;
      tmp1[i]= a[i];
      tmp2[i] = b[i];
    }
}

void dut(int a[128], int b[128], int c[128])
{
#pragma HLS DATAFLOW

  int tmp1[128], tmp2[128], tmp3[128];

  double_pass(a,b,tmp1,tmp2);
  pass(tmp2, tmp3);
  bypass(tmp1,tmp3,c);
}
