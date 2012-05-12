#include "imgLoader.h"

#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

GLuint LoadDDS (const char * filepath)
{
	std::cout << "\nDDS: Loading " << filepath;

	unsigned char Header [124];
	FILE * file;

	file = fopen (filepath , "rb"); // open the file
	if (file == NULL)
	{
		std::cout << "\nDDS: Unknown error!";
		return 0;
	}
	char filetype [4];
	fread (filetype , 1 , 4 , file);

	if (strncmp (filepath , "DDS " , 4) != 0)
	{
		fclose (file);
		std::cout << "\nDDS: Incorrect filename.";
		return 0;
	}

	fread (&Header , 124 , 1 , file);

	unsigned int height      = *(unsigned int*)&(Header[8 ]);
    unsigned int width       = *(unsigned int*)&(Header[12]);
    unsigned int linearSize  = *(unsigned int*)&(Header[16]);
    unsigned int mipMapCount = *(unsigned int*)&(Header[24]);
    unsigned int fourCC      = *(unsigned int*)&(Header[80]);

	unsigned char * buffer;
	unsigned int bufsize;

	bufsize = mipMapCount > 1 ? linearSize * 2 : linearSize;
	buffer = (unsigned char *)malloc (bufsize * sizeof (unsigned char));

	fread (buffer , 1 , bufsize , file);
	fclose (file);

	unsigned int components = (fourCC == FOURCC_DXT1) ? 3 : 4;
	unsigned int format;

	switch(fourCC)
    {
    case FOURCC_DXT1:
        format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
        break;
    case FOURCC_DXT3:
        format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
        break;
    case FOURCC_DXT5:
        format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
        break;
    default:
        free(buffer);
        return 0;
    }
}