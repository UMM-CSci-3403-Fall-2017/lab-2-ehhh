#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char* sarah = disemvowel((char*) "");
  ASSERT_STREQ("", sarah);
  free(sarah);
}

TEST(Disemvowel, HandleNoVowels) {
  char* sarah = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", sarah);
  free(sarah);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char* sarah = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", sarah);
  free(sarah);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char* sarah = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst",
		      sarah);
  free(sarah);
}

TEST(Disemvowel, HandlePunctuation) {
  char* sarah = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", 
		      sarah);
  free(sarah);
}

TEST(Disemvowel, HandleLongString) {
  char* str;
  int size;
  int i;
  char* sarah;

  size = 5000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  sarah = disemvowel(str);

  ASSERT_STREQ("xyz", sarah);

  free(sarah);
  free(str);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
