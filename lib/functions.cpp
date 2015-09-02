#include "functions.h"

Functions::Functions()
{

}
QString Functions::Syscall(const char *command, const char *type){

    FILE *fp;
    char buf[1024];
    const char* tmp;
    QString output;
    fp = popen(command, type);
     if (fp == NULL) {
       output = "Error";
     } else {
         if(strstr(type,"r")){
             while( !feof( fp ) )
             {
                 if( fgets( buf, 1024, fp ) != NULL ){
                     tmp = buf;
                     output = output + tmp;
                 }
             }
         }
         pclose(fp);
     }
     return output;

}
