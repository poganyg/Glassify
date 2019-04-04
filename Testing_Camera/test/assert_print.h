#ifndef __ASSERT_PRINT_H
#define __ASSERT_PRINT_H

//inline void assert_print(int b, const char* t) { //ORIGINAL
inline void assert_print(const char* t) {
	//if (b) return; //original
	fprintf(stderr,"%s\n",t); //modified from original
	abort();
}

// placed there so that it only affects the cpp files
#endif
