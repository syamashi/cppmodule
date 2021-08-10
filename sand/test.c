char *ft_smallest_convert_base(char *nbr, char *base_from, char *base_to);

int main(){
	char nbr[] = "-12";
	char *base_from = "01234";
	char *base_to = "0123456789";
	char *p = ft_smallest_convert_base(nbr, base_from, base_to);
	printf("%s", p);
}