//
//  main.c
//  GPS
//
//  Created by 20161104610 on 17/6/16.
//  Copyright © 2017年 20161104610. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    FILE *fr;
    FILE *fw;
    
    char ch[63];
    int a[60];
    int i;
    
    fr=fopen("/Users/a201611046101/Desktop/GPS/GPS170510.log","r+");
    fw=fopen("/Users/a20161104610/Desktop/GPS/gps.txt","w");
    
    for(i=0;i<63;i++)
    {
        fscanf("%c",&ch[i]);
        if(i>=7&&i<=12)
        {
            fscanf("%d",&a[i]);
        }
        else
        {
            break;
        }
    }
    
    for(i=0;i<63;i++)
    {
        //fprintf(fw,"%d ",a[i]);
        printf("%d ",a[i]);
    }
    printf("\n");
    
    fclose(fr);
    fclose(fw);
    
    return 0;
}
