

//给n个数,从中找出一段长度不超过m的连续子序列,使得子序列之和最大
1)	计算“区间和”的问题,一般转化为“两个前缀和相减”的形式进行求解,即
					s[ L , R ]=s[ R ]-s[ L-1 ]
		故,原问题可转化为:找出两个位置x,y,使得s[y]-s[x]最大,并且y-x<=m
2)	首先我们枚举右端点i,当i固定时,问题就变为:找到一个左端点j,其中 i-m<=j<=i-1,并且s[j]最小
3)	不妨比较一下任意两个位置j和k,如果k<j<i并且s[k]>=s[j],那么对于所有大于等于i的右端点,
    k永远不会成为最优选择.这是因为不但s[k]不小于s[ j ],并且j离i更近,长度更不容易超过m,
    即j的生存能力比k更强,所以,当j出现后,k就完全是一个无用的位置.
4)	以上比较告诉我们,可能成为最优选择的策略集合一定是一个“下标位置递增,对应的前缀和s的值也递增”的序列
5)	int a[300010],q[300010],n,m;
    int sum[300010],ans;
    int main()
    {
      cin>>n>>m;
      for(int i=1;i<=n;i++)
      {
          scanf("%d",&a[i]);
          sum[i]=sum[i-1]+a[i];
      }
      int l=1,r=1;
      q[l]=0;
      for(int i=1;i<=n;i++)
      {
          while(l<=r&&i-q[l]>m) l++;
          ans=max(ans,sum[i]-sum[q[l]]);
          while(l<=r&&sum[q[r]]>=sum[i]) r--;
          q[++r]=i;
      }
       cout<<ans<<endl;
    }    
