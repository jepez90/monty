void copy_buffer(char *origin, char *dest)
{
	int i;

	for (i = 0;origin[i]; i++)
		dest[i] = origin[i];

	dest[i]= '\0';

}
