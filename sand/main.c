#include <unistd.h>
#include <stdio.h>

char *ft_smallest_convert_base(char *nbr, char *base_from, char *base_to)
{
	long base[999]={},cnt=0,base2[999]={},flag=0,L=0,id=9999;
	char *c=base_from,*n=nbr,*ret=calloc(9999,1);
	// *base_from読み込み
	while(*c){
		if(base[*c]) return NULL;
		base[*c]=++cnt;
		++c;
	}
	if(cnt<2||base[43]||base[45]||base[32]) return NULL;
    // *nbr読み込み。Lで10進数化
 	while(*n == '+' || *n == '-'){
		if(*n == '-') flag^=1;
		n++;
	}
	while(*n && base[*n]){
		L=L*cnt+base[*n]-1;
		++n;
	}
	c=base_to,cnt=0;
	// *base_to読み込み
	while(*c){
		if(base2[*c]) return NULL;
		base2[*c]=++cnt;
		++c;
	}
	if(cnt<2||base2[43]||base2[45]||base2[32]) return NULL;
	// 戻り値ret作成
	if(!L){ret[0]='0';return ret;}
	while(L){
		ret[--id]=base_to[L%cnt];
		L/=cnt;
	}
	if(flag)ret[--id]='-';
	ret=ret+id;
	return ret;
}

