#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char	str[20000000]				= {};
	int		i						= 0;
	int		j						= 0;
	int		n						= 0;
	int		length_of_arr			= 0;
	int		target_number			= 0;
	int		arr[100000]				= {};
	int		length					= 0;
	int		sum						= 0;
	int		result					= 0;
	fgets( str, 256, stdin );
	for ( i = 0; str[i] != ' '; i++ ) {}
	str[i] = '\0';
	length_of_arr = atoi(&str[0]);
	target_number = atoi(&str[i+1]);
	
	fgets( str, 20000000, stdin );
	j = 0;
	for ( i = 0; i < length_of_arr - 1; i++ ) {
		n = j;
		for ( ; str[j] != ' '; j++  ) {
		}
		str[j] = '\0';
		arr[i] = atoi(&str[n]);
		j++;
	}
	arr[i] = atoi(&str[j]);
	
	for ( length = 1; length <= length_of_arr; length++ ) {
		for ( i = 0; i < length_of_arr - length +1 ; i++ ) {
			sum = 0;
			for ( j = i; j < i + length; j++ ) {
				sum += arr[j] ;
			}
			if ( sum >= target_number ) {
				result = length;
				
				//printf("%d %d \n", result, i);
				break;
			}
		}
		if ( result > 0 ) {
			break;
		}
	}
	
	printf("%d\n", result);
	
	return 0;
}
