#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int check_newline(char *str)
{
    int index;
    index = 0;
    while(str[index])
    {
        if(str[index] == '\n')
        return(index);
        index++;    
    }
    return(-1);
    
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > strlen(s))
		return (strdup(""));
	p = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!p)
		return (0);
	while (i < len)
	{
		p[i] = *(s + start + i);
		i++;
	}
	p[i] = '\0';
	return (p);
}

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE +1];
    int reader = read(fd,buffer,BUFFER_SIZE);
    int index;
    char *res;
    static char *line;
    while (reader > 0)
    {
        res =strdup(buffer);
        index = check_newline(res);
        // printf("%d", index);
        // break;
        if(index != -1)
             return(ft_substr(res,0,3));
            
            
        

        

    }
    // return(line);
    
}



int main()
{
    int fd = open("hi.txt",O_RDONLY);
    printf("%s",get_next_line(fd));

}