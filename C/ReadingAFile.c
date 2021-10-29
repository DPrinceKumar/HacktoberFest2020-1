#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;
  char c='a';
  fp = fopen("file1.txt","r");
  if(fp==NULL){
    printf("Cannot read data");
  }
  else{
    while(c!=EOF){
      c = fgetc(fp);
      printf("%c",c);
    }
  }

  fclose(fp);

  return 0;
}
