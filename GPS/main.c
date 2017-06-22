//
//  main.c
//  GPS
//
//  Created by 20161104610 on 17/6/16.
//  Copyright © 2017年 20161104610. All rights reserved.
//

#include <stdio.h>

int main()
{
    int i,j;
    int b[10][10];
    char a[100][100];
    
    FILE *fr;
    
    fr=fopen("/Users/a201611046101/Desktop/GPS/GPS170510.log","r+");

    for(i=1;i<3;i++)
    {
        fgets(a[i],62,fr);
        printf("%s",a[i]);
        for(j=8;j<=13;j++)
        {
            //fscanf(fr,"%d",b[j]);
            printf("%d",b[i][j]);
        }
    }

    printf("\n");
    
    fclose(fr);
}
