#include <cstdio>

#include "../lib/tinyjson.hpp"

#define INPUT_SIZE_LIMIT 64000 // 64 KB
#define MAX_INPUT_LINE_LENGTH 4000 // 64 KB
#define LAST_INPUT_INDEX 63999 
#define OUTPUT_SIZE_LIMIT 20000 // 20 KB

int main()
{

  char in[MAX_INPUT_LINE_LENGTH];
  char str[INPUT_SIZE_LIMIT];

  while(std::fgets(in, sizeof(in), stdin) != NULL){
    std::strncat(str, in, MAX_INPUT_LINE_LENGTH - strlen(str) - 1);
  }

  std::printf("%s\n", str);
  tiny::TinyJson json;
	json.ReadJson(str);

  // int token = json.Get<int>("token");
  

  std::printf("{ \"operations\": [] }\n");
  return 0;
}