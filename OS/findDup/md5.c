#include <openssl/md5.h>
#include <unistd.h>
#include <fcntl.h>
#include "md5.h"

int MD5Function(char* path, char* key){
	MD5_CTX c;
	char buf[512];
	ssize_t bytes;
	int fd;
	unsigned char out[MD5_DIGEST_LENGTH];
	fd= open(path,O_RDONLY);
	if(fd<0)
	{
		return 0;
	}
	MD5_Init(&c);
	bytes=read(fd,buf,512);
	while(bytes > 0)
	{
		MD5_Update(&c, buf, bytes);
	    bytes=read(fd, buf, 512);
	}
	MD5_Final(key, &c);

	return 1;
}