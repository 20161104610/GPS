//
//  main.c
//  GPS
//
//  Created by 20161104610 on 17/6/16.
//  Copyright © 2017年 20161104610. All rights reserved.
//

#include <stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int i,j;
    int flag;
    char name[10];
    char utc[10],yesno[10],nor[10],eas[10],lon[10],groud[10],time[10],more[10];
    char a[100][100];
    
    FILE *fr;
    FILE *fw;
    
    flag=1;
    
    fr=fopen("/Users/a201611046101/Desktop/GPS/GPS170510.log","r+");
    fw=fopen("/Users/a201611046101/Desktop/GPS/GPS.csv","w");

    for(i=0;i<=5;i++)
    {
        fgets(a[i],63,fr);
        printf("%s",a[i]);
    }
    printf("\n");
    
    //fprintf(fw,"时分秒,效用,北纬,东经,地面速率,航向,月日年,磁偏角\n");
    fprintf(fw,"时分秒,效用,北纬,东经,地面速率,航向,月日年,磁偏角\n");
    
    
    for(j=0;j<=5;j++)
    {
        strncpy(name,&a[j][0],4);
        if(name[1]=='G')
        {
            if(name[3]=='R')
            {
                strncpy(utc,&a[j][7],6);
                utc[6]='\0';
                strncpy(yesno,&a[j][14],1);
                yesno[1]='\0';
                strncpy(nor,&a[j][16],9);
                nor[9]='\0';
                strncpy(eas,&a[j][27],9);
                eas[9]='\0';
                strncpy(lon,&a[j][39],5);
                lon[5]='\0';
                strncpy(groud,&a[j][45],5);
                groud[5]='\0';
                strncpy(time,&a[j][51],6);
                time[6]='\0';
                strncpy(more,&a[j][59],3);
                more[3]='\0';
                fprintf(fw,"%s,%s,%s%s,%s,%s,%s,%s\n",utc,yesno,nor,eas,lon,groud,time,more);
            }
            else if(name[3]=='G')
            {
                fprintf(fw,"\n");
            }
        }
        else
            continue;
    }
    
    fclose(fr);
    
}
