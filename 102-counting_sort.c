#include	"sort.h"

/**
*	counting_sort	-	Sorts	an	array	of	integers	in	ascending
*	order	using	Counting	sort	algorithm
*	@array:	The	array	to	be	sorted
*	@size:	Number	of	elements	in	the	array
*/
void	counting_sort(int	*array,	size_t	size)
{
int	max;
int	*count,	*output;
size_t	i;

if	(!array	||	size	<	2)
return;
max	=	array[0];
for	(i	=	1;	i	<	size;	i++)
{
if	(array[i]	>	max)
max	=	array[i];
}
count	=	malloc(sizeof(int)	*	(max	+	1));
output	=	malloc(sizeof(int)	*	size);
if	(!count	||	!output)
{
free(count);
free(output);
return;
}
for	(i	=	0;	i	<=	(size_t)max;	i++)
count[i]	=	0;
for	(i	=	0;	i	<	size;	i++)
count[array[i]]++;
for	(i	=	1;	i	<=	(size_t)max;	i++)
count[i]	+=	count[i	-	1];
print_array(count,	(size_t)max	+	1);
for	(i	=	size	-	1;	i	>	0;	i--)
{
output[count[array[i]]	-	1]	=	array[i];
count[array[i]]--;
}
for	(i	=	0;	i	<	size;	i++)
array[i]	=	output[i];
free(count);
free(output);
}
