#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

int	main(void)
{
	const char	*str = "asdasdasd";
	const char	*str2 = "42";

	// ft_strlen
	assert(strlen(str) == ft_strlen(str));
	assert(strlen(str2) == ft_strlen(str2));

	// ft_strcpy
	char *oDest = calloc(10, 1);
	char *ftDest = calloc(10, 1);
	char *src = "12345678";

	strcpy(oDest, src);
	ft_strcpy(ftDest, src);

	assert(strcmp(oDest, ftDest) == 0);

	// ft_strcmp
	assert(strcmp(oDest, ftDest) == ft_strcmp(oDest, ftDest));
	
	char *tStr1 = "asdqm,cfxdlivj";
	char *tStr2 = "dsdqm,cfxdlivj";

	assert(strcmp(tStr1, tStr2) == ft_strcmp(tStr1, tStr2));

	char *tStr3 = "asdZernbmdsf";
	char *tStr4 = "asdqwe3rtew";

	assert(strcmp(tStr3, tStr4) == ft_strcmp(tStr3, tStr4));

	// ft_write
	int oRet = write(1, str, strlen(str));
	int oErrno = errno;

	int ftRet = ft_write(1, str, ft_strlen(str));
	int ftErrno = errno;

	assert(oRet == ftRet);
	assert(oErrno == ftErrno);
	
	oRet = write(3, str, strlen(str));
	oErrno = errno;
	ftRet = ft_write(3, str, ft_strlen(str));
	ftErrno = errno;

	assert(oRet == ftRet);
	assert(oErrno == ftErrno);

	printf("\n=== Input test ===\nplease input message 2 time\n");

	// ft_read
	char *oRead = calloc(10, 1);
	char *ftRead = calloc(10, 1);
	
	oRet = read(0, oRead, 10);
	oErrno = errno;
	ftRet = ft_read(0, ftRead, 10);
	ftErrno = errno;

	assert(oRet == ftRet);
	assert(oErrno == ftErrno);

	oRet = read(3, oRead, 10);
	oErrno = errno;
	ftRet = ft_read(3, ftRead, 10);
	ftErrno = errno;

	assert(oRet == ftRet);
	assert(oErrno == ftErrno);

	// ft_strdup
	char *oDup = strdup(str);
	char *ftDup = ft_strdup(str);

	assert(strcmp(oDup, ftDup) == 0);

	// done
	printf("Test Success\n");
	return 0;
}