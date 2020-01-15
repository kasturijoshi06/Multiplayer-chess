#include<simplecpp>
#define midx 403+((tileX-1)*80)
#define midy 104+((tileY-'a')*80)
#define centerX 683
#define centerY 384
#define blackCol COLOR(0,0,0)
#define whiteCol COLOR(255,255,255)
#define newX 403+(80*toX)
#define newY 114+(80*toY)
class tile{
   int x;
   char y;
   char color;
   char type;
   int pieceNo;
   public:
   char retType(){return type;}
   char retColor(){return color;}
   int retPieceNo(){return pieceNo;}
   void set(char a,int p,char q,char colour,int num){
       type=a;
       x=p;
       y=q;
       color=colour;
       pieceNo=num;
   }
   void change(char a, char colour,int num){
       type=a;
       color=colour;
       pieceNo=num;
   }
   int retX(){return x;}
   char retY(){return y;}
};

void movePawn(int tileX, char tileY,Rectangle &pawnBase,Rectangle &pawnStalk,Circle &pawnHead,char color){
   pawnHead.moveTo(midx,midy+2);
   pawnStalk.moveTo(midx,midy+18);
   pawnBase.moveTo(midx,midy+28);
   if(color=='b'){
      pawnHead.setFill(true);
      pawnStalk.setFill(true);
      pawnBase.setFill(true);
   }
}

void moveKilledPawn(int x,int y,Rectangle &pawnBase,Rectangle &pawnStalk,Circle &pawnHead){
   pawnHead.moveTo(x,y+2);
   pawnStalk.moveTo(x,y+18);
   pawnBase.moveTo(x,y+28);
}

void moveRook(int tileX,char tileY,Rectangle &rookBase,Rectangle &rookF1,Rectangle &rookF2,Rectangle &rookF3,Line &l1,Line &l2,char color){
   rookBase.moveTo(midx,midy);
   rookF1.moveTo(midx,midy-29);
   rookF2.moveTo(midx+16,midy-29);
   rookF3.moveTo(midx-15,midy-29);
   l1.moveTo(midx,midy-15);
   l2.moveTo(midx,midy-10);
   if(color=='b'){
      rookBase.setFill(true);
      rookF1.setFill(true);
      rookF2.setFill(true);
      rookF3.setFill(true);
      l1.setColor(whiteCol);
      l2.setColor(whiteCol);
   }
}

void moveKilledRook(int x,int y,Rectangle &rookBase,Rectangle &rookF1,Rectangle &rookF2,Rectangle &rookF3,Line &l1,Line &l2){
   rookBase.moveTo(x,y);
   rookF1.moveTo(x,y-29);
   rookF2.moveTo(x+16,y-29);
   rookF3.moveTo(x-15,y-29);
   l1.moveTo(x,y-15);
   l2.moveTo(x,y-10);
}

void moveHorse(int tileX,char tileY,Rectangle &stalk,Rectangle &hair,Rectangle &face1,Rectangle &face2,Rectangle &base,char color){
   int flag=0;
   if(color=='w'){
     flag=1;
   }
   else{
     stalk.setFill(true);
     hair.setFill(true);
     face1.setFill(true);
     face2.setFill(true);
     base.setFill(true);
   }
   stalk.moveTo(midx+(pow(-1,flag)*5),midy+6);
   hair.moveTo(midx+(pow(-1,flag)*13),midy-20);
   face1.moveTo(midx+(pow(-1,flag)*4),midy-18);
   face2.moveTo(midx-(pow(-1,flag)*11),midy-16);
   base.moveTo(midx+(pow(-1,flag)*5),midy+25);
}

void moveKilledHorse(int x,int y,Rectangle &stalk,Rectangle &hair,Rectangle &face1,Rectangle &face2,Rectangle &base,char color){
   int flag=0;
   if(color=='w'){
     flag=1;
   }
   stalk.moveTo(x+(pow(-1,flag)*5),y+6);
   hair.moveTo(x+(pow(-1,flag)*13),y-20);
   face1.moveTo(x+(pow(-1,flag)*4),y-18);
   face2.moveTo(x-(pow(-1,flag)*11),y-16);
   base.moveTo(x+(pow(-1,flag)*5),y+25);
}

void moveBishop(int tileX,char tileY,Circle &c1,Circle &c2,Circle &c3,Rectangle &stalk,Rectangle &base,char color){
   c1.moveTo(midx,midy-32);
   c2.moveTo(midx,midy-22);
   c3.moveTo(midx,midy-8);
   stalk.moveTo(midx,midy+13);
   base.moveTo(midx,midy+31);
   if(color=='b'){
      c1.setFill(true);
      c2.setFill(true);
      c3.setFill(true);
      stalk.setFill(true);
      base.setFill(true);
   }
}

void moveKilledBishop(int x,int y,Circle &c1,Circle &c2,Circle &c3,Rectangle &stalk,Rectangle &base){
   c1.moveTo(x,y-32);
   c2.moveTo(x,y-22);
   c3.moveTo(x,y-8);
   stalk.moveTo(x,y+13);
   base.moveTo(x,y+31);
}

void moveQueen(int tileX,char tileY,Rectangle &base,Line &l1,Line &l2,Line &l3,Line &l4,Line &l5,Line &l6,Line &l7,Line &l8,Line &l9,Circle &c1,Circle &c2,Circle &c3,char color){
   base.moveTo(midx,midy+30);
   l1.moveTo(midx-12.5,midy+22.5);
   l2.moveTo(midx+12.5,midy+22.5);
   l3.moveTo(midx,midy+20);
   l4.moveTo(midx-12.5,midy+10);
   l5.moveTo(midx-10,midy+7.5);
   l6.moveTo(midx-2.5,midy+5);
   l7.moveTo(midx+2.5,midy+5);
   l8.moveTo(midx+10,midy+7.5);
   l9.moveTo(midx+12.5,midy+10);
   c1.moveTo(midx-15,midy-7);
   c2.moveTo(midx,midy-12);
   c3.moveTo(midx+15,midy-7);
   if(color=='b'){
     base.setFill(true);
     c1.setFill(true);
     c2.setFill(true);
     c3.setFill(true);
     }
}

void moveKilledQueen(int x,int y,Rectangle &base,Line &l1,Line &l2,Line &l3,Line &l4,Line &l5,Line &l6,Line &l7,Line &l8,Line &l9,Circle &c1,Circle &c2,Circle &c3){
   base.moveTo(x,y+30);
   l1.moveTo(x-12.5,y+22.5);
   l2.moveTo(x+12.5,y+22.5);
   l3.moveTo(x,y+20);
   l4.moveTo(x-12.5,y+10);
   l5.moveTo(x-10,y+7.5);
   l6.moveTo(x-2.5,y+5);
   l7.moveTo(x+2.5,y+5);
   l8.moveTo(x+10,y+7.5);
   l9.moveTo(x+12.5,y+10);
   c1.moveTo(x-15,y-7);
   c2.moveTo(x,y-12);
   c3.moveTo(x+15,y-7);
}

void moveKing(int tileX,char tileY,Circle &c1,Circle &c2,Line &l1,Line &l2,Line &l3,Line &l4,Rectangle &base1,Rectangle &base2,Rectangle &head,Line &l5,Line &l6,char color){
   c1.moveTo(midx-16,midy);
   c2.moveTo(midx+16,midy);
   l1.moveTo(midx-16,midy);
   l2.moveTo(midx-16,midy);
   l3.moveTo(midx+16,midy);
   l4.moveTo(midx+16,midy);
   base1.moveTo(midx,midy+21);
   base2.moveTo(midx,midy+31);
   head.moveTo(midx,midy-16);
   l5.moveTo(midx,midy-27);
   l6.moveTo(midx,midy-27);
   if(color=='b'){
      c1.setFill(true);
      c2.setFill(true);
      l1.setColor(whiteCol);
      l2.setColor(whiteCol);
      l3.setColor(whiteCol);
      l4.setColor(whiteCol);
      base1.setFill(true);
      base2.setFill(true);
      head.setFill(true);
   }
}

void moveKilledKing(int x, int y,Circle &c1,Circle &c2,Line &l1,Line &l2,Line &l3,Line &l4,Rectangle &base1,Rectangle &base2,Rectangle &head,Line &l5,Line &l6){
   c1.moveTo(x-16,y);
   c2.moveTo(x+16,y);
   l1.moveTo(x-16,y);
   l2.moveTo(x-16,y);
   l3.moveTo(x+16,y);
   l4.moveTo(x+16,y);
   base1.moveTo(x,y+21);
   base2.moveTo(x,y+31);
   head.moveTo(x,y-16);
   l5.moveTo(x,y-27);
   l6.moveTo(x,y-27);
}

void setBoard(tile chessboard[8][8]){
    for(int i=0;i<8;i++){
       for(int j=0;j<8;j++){
          chessboard[i][j].set('0',i,char('a'+j),'0',0);
       }
    }
    for(int i=0;i<8;i++){
       chessboard[1][i].set('P',2,char('a'+i),'w',i+1);
       chessboard[6][i].set('P',7,char('a'+i),'b',i+1);
    }
    chessboard[7][2].set('B',8,'c','b',1);
    chessboard[0][2].set('B',1,'c','w',1);
    chessboard[7][5].set('B',8,'f','b',2);
    chessboard[0][5].set('B',1,'f','w',2);
    chessboard[7][1].set('H',8,'b','b',1);
    chessboard[0][1].set('H',1,'b','w',1);
    chessboard[7][6].set('H',8,'g','b',2);
    chessboard[0][6].set('H',1,'g','w',2);
    chessboard[7][0].set('R',8,'a','b',1);
    chessboard[0][0].set('R',1,'a','w',1);
    chessboard[7][7].set('R',8,'h','b',2);
    chessboard[0][7].set('R',1,'h','w',2);
    chessboard[7][3].set('Q',8,'d','b',1);
    chessboard[0][3].set('Q',1,'d','w',1);
    chessboard[7][4].set('K',8,'e','b',1);
    chessboard[0][4].set('K',1,'e','w',1);
}

int mod(int x){
 if(x>=0){return x;}
 else{return (0-x);}
}

int check(tile chessboard[8][8],char turn){
   int check=0,kingX,kingY;
   for(int i=0;i<8;i++)
      {for(int j=0;j<8;j++){
          if(chessboard[i][j].retType()=='K' && chessboard[i][j].retColor()==turn){
             kingX=chessboard[i][j].retX()-1;
             kingY=chessboard[i][j].retY()-'a';
           }
       }
   }
   int k=kingX;
   int l=kingY;
   int m;
   switch(turn){
   case 'w':if(chessboard[kingX+1][kingY+1].retType()=='P' && chessboard[kingX+1][kingY+1].retColor()=='b'
               && check==0 && kingX+1>=0 && kingX+1<=7 && kingY+1>=0 && kingY+1<=7)check=1;
            if(chessboard[kingX+1][kingY-1].retType()=='P' && chessboard[kingX+1][kingY-1].retColor()=='b'
               && check==0 && kingX+1>=0 && kingX+1<=7 && kingY-1>=0 && kingY-1<=7)check=1;

            if(chessboard[kingX+2][kingY+1].retType()=='H' && chessboard[kingX+2][kingY+1].retColor()=='b'
               && check==0 && kingX+2>=0 && kingX+2<=7 && kingY+1>=0 && kingY+1<=7)check=1;
            if(chessboard[kingX-2][kingY-1].retType()=='H' && chessboard[kingX-2][kingY-1].retColor()=='b'
               && check==0 && kingX-2>=0 && kingX-2<=7 && kingY-1>=0 && kingY-1<=7)check=1;
            if(chessboard[kingX+1][kingY+2].retType()=='H' && chessboard[kingX+1][kingY+2].retColor()=='b'
               && check==0 && kingX+1>=0 && kingX+1<=7 && kingY+2>=0 && kingY+2<=7)check=1;
            if(chessboard[kingX-1][kingY-2].retType()=='H' && chessboard[kingX-1][kingY-2].retColor()=='b'
               && check==0 && kingX-1>=0 && kingX-1<=7 && kingY-2>=0 && kingY-2<=7)check=1;
            if(chessboard[kingX+2][kingY-1].retType()=='H' && chessboard[kingX+2][kingY-1].retColor()=='b'
               && check==0 && kingX+2>=0 && kingX+2<=7 && kingY-1>=0 && kingY-1<=7)check=1;
            if(chessboard[kingX-2][kingY+1].retType()=='H' && chessboard[kingX-2][kingY+1].retColor()=='b'
               && check==0 && kingX-2>=0 && kingX-2<=7 && kingY+1>=0 && kingY+1<=7)check=1;
            if(chessboard[kingX-1][kingY+2].retType()=='H' && chessboard[kingX-1][kingY+2].retColor()=='b'
               && check==0 && kingX-1>=0 && kingX-1<=7 && kingY+2>=0 && kingY+2<=7)check=1;
            if(chessboard[kingX+1][kingY-2].retType()=='H' && chessboard[kingX+1][kingY-2].retColor()=='b'
               && check==0 && kingX+1>=0 && kingX+1<=7 && kingY-2>=0 && kingY-2<=7)check=1;

            for(int i=0;i<2;i++){
               for(int j=0;j<2;j++){
                  m=1;
                  do{
                    k=kingX+(m*pow(-1,i));
                    l=kingY+(m*pow(-1,j));
                    m++;
                  }while(chessboard[k][l].retType()=='0' && k<=7 && l<=7 && k>=0 && l>=0);
                  if((chessboard[k][l].retType()=='Q' || chessboard[k][l].retType()=='B') && chessboard[k][l].retColor()=='b')check=1;
               }
            }

            k=kingX;l=kingY;
            for(int i=0;i<2;i++){
               m=1;
               do{
                 k=kingX+(m*pow(-1,i));
                 m++;
               }while(chessboard[k][l].retType()=='0' && k<=7 && l<=7 && k>=0 && l>=0);
               if((chessboard[k][l].retType()=='Q' || chessboard[k][l].retType()=='R') && chessboard[k][l].retColor()=='b')check=1;
            }

            k=kingX;l=kingY;
            for(int i=0;i<2;i++){
               m=1;
               do{
                 l=kingY+(m*pow(-1,i));
                 m++;
               }while(chessboard[k][l].retType()=='0' && k<=7 && l<=7 && k>=0 && l>=0);
               if((chessboard[k][l].retType()=='Q' || chessboard[k][l].retType()=='R') && chessboard[k][l].retColor()=='b')check=1;
            }
            break;
   case 'b':if(chessboard[kingX-1][kingY+1].retType()=='P' && chessboard[kingX-1][kingY+1].retColor()=='w'
               && check==0 && kingX-1>=0 && kingX-1<=7 && kingY+1>=0 && kingY+1<=7)check=1;
            if(chessboard[kingX-1][kingY-1].retType()=='P' && chessboard[kingX-1][kingY-1].retColor()=='w'
               && check==0 && kingX-1>=0 && kingX-1<=7 && kingY-1>=0 && kingY-1<=7)check=1;

            if(chessboard[kingX+2][kingY+1].retType()=='H' && chessboard[kingX+2][kingY+1].retColor()=='w'
               && check==0 && kingX+2>=0 && kingX+2<=7 && kingY+1>=0 && kingY+1<=7)check=1;
            if(chessboard[kingX-2][kingY-1].retType()=='H' && chessboard[kingX-2][kingY-1].retColor()=='w'
               && check==0 && kingX-2>=0 && kingX-2<=7 && kingY-1>=0 && kingY-1<=7)check=1;
            if(chessboard[kingX+1][kingY+2].retType()=='H' && chessboard[kingX+1][kingY+2].retColor()=='w'
               && check==0 && kingX+1>=0 && kingX+1<=7 && kingY+2>=0 && kingY+2<=7)check=1;
            if(chessboard[kingX-1][kingY-2].retType()=='H' && chessboard[kingX-1][kingY-2].retColor()=='w'
               && check==0 && kingX-1>=0 && kingX-1<=7 && kingY-2>=0 && kingY-2<=7)check=1;
            if(chessboard[kingX+2][kingY-1].retType()=='H' && chessboard[kingX+2][kingY-1].retColor()=='w'
               && check==0 && kingX+2>=0 && kingX+2<=7 && kingY-1>=0 && kingY-1<=7)check=1;
            if(chessboard[kingX-2][kingY+1].retType()=='H' && chessboard[kingX-2][kingY+1].retColor()=='w'
               && check==0 && kingX-2>=0 && kingX-2<=7 && kingY+1>=0 && kingY+1<=7)check=1;
            if(chessboard[kingX-1][kingY+2].retType()=='H' && chessboard[kingX-1][kingY+2].retColor()=='w'
               && check==0 && kingX-1>=0 && kingX-1<=7 && kingY+2>=0 && kingY+2<=7)check=1;
            if(chessboard[kingX+1][kingY-2].retType()=='H' && chessboard[kingX+1][kingY-2].retColor()=='w'
               && check==0 && kingX+1>=0 && kingX+1<=7 && kingY-2>=0 && kingY-2<=7)check=1;

            for(int i=0;i<2;i++){
               for(int j=0;j<2;j++){
                  m=1;
                  do{
                    k=kingX+(m*pow(-1,i));
                    l=kingY+(m*pow(-1,j));
                    m++;
                  }while(chessboard[k][l].retType()=='0' && k<=7 && l<=7 && k>=0 && l>=0);
                  if((chessboard[k][l].retType()=='Q' || chessboard[k][l].retType()=='B') && chessboard[k][l].retColor()=='w')check=1;
               }
            }

            k=kingX;l=kingY;
            for(int i=0;i<2;i++){
               m=1;
               do{
                 k=kingX+(m*pow(-1,i));
                 m++;
               }while(chessboard[k][l].retType()=='0' && k<=7 && l<=7 && k>=0 && l>=0);
               if((chessboard[k][l].retType()=='Q' || chessboard[k][l].retType()=='R') && chessboard[k][l].retColor()=='w')check=1;
            }
            k=kingX;l=kingY;
            for(int i=0;i<2;i++){
               m=1;
               do{
                 l=kingY+(m*pow(-1,i));
                 m++;
               }while(chessboard[k][l].retType()=='0' && k<=7 && l<=7 && k>=0 && l>=0);
               if((chessboard[k][l].retType()=='Q' || chessboard[k][l].retType()=='R') && chessboard[k][l].retColor()=='w')check=1;
            }
            break;
   }
   return check;
}

int checkMate(tile chessboard[8][8],char turn){
   int mate=1,k,l,m;
   char opponent;
   tile temp;
   if(turn=='w')opponent='b';
   else opponent='w';
   for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
         if(chessboard[i][j].retColor()==turn && mate==1){
            switch(chessboard[i][j].retType()){
                case 'P':if(turn=='w'){
                            if(i+1<=7 && i+1>=0 && j<=7 && j>=0)
                            if(chessboard[i+1][j].retType()=='0' && mate==1){
                               chessboard[i+1][j].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                         chessboard[i][j].retPieceNo());
                               chessboard[i][j].change('0','0',0);
                               if(check(chessboard,turn)==0)mate=0;
                               chessboard[i][j].change(chessboard[i+1][j].retType(),chessboard[i+1][j].retColor(),
                                                       chessboard[i+1][j].retPieceNo());
                               chessboard[i+1][j].change('0','0',0);
                            }
                            if(i+2<=7 && i+2>=0 && i+1<=7 && i+1>=0 && j<=7 && j>=0)
                            if(chessboard[i+2][j].retType()=='0' && chessboard[i+1][j].retType()=='0' && i==1 && mate==1){
                               chessboard[i+2][j].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                         chessboard[i][j].retPieceNo());
                               chessboard[i][j].change('0','0',0);
                               if(check(chessboard,turn)==0)mate=0;
                               chessboard[i][j].change(chessboard[i+2][j].retType(),chessboard[i+2][j].retColor(),
                                                       chessboard[i+2][j].retPieceNo());
                               chessboard[i+2][j].change('0','0',0);
                            }
                            if(i+1<=7 && i+1>=0 && j+1<=7 && j+1>=0)
                            if(chessboard[i+1][j+1].retType()!='0' && chessboard[i+1][j+1].retColor()==opponent && mate==1){
                               temp=chessboard[i+1][j+1];
                               chessboard[i+1][j+1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                         chessboard[i][j].retPieceNo());
                               chessboard[i][j].change('0','0',0);
                               if(check(chessboard,turn)==0)mate=0;
                               chessboard[i][j].change(chessboard[i+1][j+1].retType(),chessboard[i+1][j+1].retColor(),
                                                       chessboard[i+1][j+1].retPieceNo());
                               chessboard[i+1][j+1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                            }
                            if(i+1<=7 && i+1>=0 && j-1<=7 &&j-1>=0)
                            if(chessboard[i+1][j-1].retType()!='0' && chessboard[i+1][j-1].retColor()==opponent && mate==1){
                               temp=chessboard[i+1][j-1];
                               chessboard[i+1][j-1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                           chessboard[i][j].retPieceNo());
                               chessboard[i][j].change('0','0',0);
                               if(check(chessboard,turn)==0)mate=0;
                               chessboard[i][j].change(chessboard[i+1][j-1].retType(),chessboard[i+1][j-1].retColor(),
                                                       chessboard[i+1][j-1].retPieceNo());
                               chessboard[i+1][j-1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                            }
                         }
                         if(turn=='b'){
                            if(i-1<=7 && i-1>=0 && j<=7 && j>=0)
                            if(chessboard[i-1][j].retType()=='0' && mate==1){
                               chessboard[i-1][j].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                         chessboard[i][j].retPieceNo());
                               chessboard[i][j].change('0','0',0);
                               if(check(chessboard,turn)==0){mate=0;}
                               chessboard[i][j].change(chessboard[i-1][j].retType(),chessboard[i-1][j].retColor(),
                                                       chessboard[i-1][j].retPieceNo());
                               chessboard[i-1][j].change('0','0',0);
                            }
                            if(i-2<=7 && i-2>=0 && i-1<=7 && i-1>=0 && j<=7 && j>=0)
                            if(chessboard[i-2][j].retType()=='0' && chessboard[i-1][j].retType()=='0' && i==6 && mate==1){
                               chessboard[i-2][j].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                         chessboard[i][j].retPieceNo());
                               chessboard[i][j].change('0','0',0);
                               if(check(chessboard,turn)==0){mate=0;}
                               chessboard[i][j].change(chessboard[i-2][j].retType(),chessboard[i-2][j].retColor(),
                                                       chessboard[i-2][j].retPieceNo());
                               chessboard[i-2][j].change('0','0',0);
                            }
                            if(i-1<=7 && i-1>=0 && j+1<=7 && j+1>=0)
                            if(chessboard[i-1][j+1].retType()!='0' && chessboard[i-1][j+1].retColor()==opponent && mate==1){
                               temp=chessboard[i-1][j+1];
                               chessboard[i-1][j+1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                           chessboard[i][j].retPieceNo());
                               chessboard[i][j].change('0','0',0);
                               if(check(chessboard,turn)==0){mate=0;}
                               chessboard[i][j].change(chessboard[i-1][j+1].retType(),chessboard[i-1][j+1].retColor(),
                                                       chessboard[i-1][j+1].retPieceNo());
                               chessboard[i-1][j+1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                            }
                            if(i-1<=7 && i-1>=0 && j-1<=7 && j-1>=0)
                            if(chessboard[i-1][j-1].retType()!='0' && chessboard[i-1][j-1].retColor()==opponent && mate==1){
                               temp=chessboard[i-1][j-1];
                               chessboard[i-1][j-1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                           chessboard[i][j].retPieceNo());
                               chessboard[i][j].change('0','0',0);
                               if(check(chessboard,turn)==0){mate=0;}
                               chessboard[i][j].change(chessboard[i-1][j-1].retType(),chessboard[i-1][j-1].retColor(),
                                                       chessboard[i-1][j-1].retPieceNo());
                               chessboard[i-1][j-1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                            }
                         }
                         break;
                case 'R':k=i;l=j;
                         for(int p=0;p<2;p++){
                           m=1;
                           do{
                             k=i+(m*pow(-1,p));
                             m++;
                             if(chessboard[k][l].retColor()!=turn){
                                temp=chessboard[k][l];
                                chessboard[k][l].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                                chessboard[i][j].change('0','0',0);
                                if(check(chessboard,turn)==0)mate=0;
                                chessboard[i][j].change(chessboard[k][l].retType(),chessboard[k][l].retColor(),
                                                        chessboard[k][l].retPieceNo());
                                chessboard[k][l].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                             }
                           }while(chessboard[k][l].retType()=='0' && mate==1 && k<=7 && l<=7 && k>=0 && l>=0);


                           }
                         k=i;l=j;
                         for(int p=0;p<2;p++){
                           m=1;
                           do{
                            l=j+(m*pow(-1,p));
                            m++;
                            if(chessboard[k][l].retColor()!=turn){
                               temp=chessboard[k][l];
                               chessboard[k][l].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                       chessboard[i][j].retPieceNo());
                               chessboard[i][j].change('0','0',0);
                               if(check(chessboard,turn)==0)mate=0;
                               chessboard[i][j].change(chessboard[k][l].retType(),chessboard[k][l].retColor(),
                                                       chessboard[k][l].retPieceNo());
                               chessboard[k][l].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                            }
                           }while(chessboard[k][l].retType()=='0' && mate==1 && k<=7 && l<=7 && k>=0 && l>=0);
                         }
                         break;
                case 'B':k=i;l=j;
                         for(int p=0;p<2;p++){
                            for(int q=0;q<2;q++){
                               m=1;
                               do{
                                 k=i+(m*pow(-1,p));
                                 l=j+(m*pow(-1,q));
                                 m++;
                                 if(chessboard[k][l].retColor()!=turn){
                                    temp=chessboard[k][l];
                                    chessboard[k][l].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                            chessboard[i][j].retPieceNo());
                                    chessboard[i][j].change('0','0',0);
                                    if(check(chessboard,turn)==0)mate=0;
                                    chessboard[i][j].change(chessboard[k][l].retType(),chessboard[k][l].retColor(),
                                                            chessboard[k][l].retPieceNo());
                                    chessboard[k][l].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                 }
                               }while(chessboard[k][l].retType()=='0' && mate==1 && k<=7 && l<=7 && k>=0 && l>=0);
                            }
                         }
                         break;
                case 'H':if(i+2<=7 && j+1<=7 && i+2>=0 && j+1>=0 && chessboard[i+2][j+1].retColor()!=turn && mate==1){
                            temp=chessboard[i+2][j+1];
                            chessboard[i+2][j+1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0)mate=0;
                            chessboard[i][j].change(chessboard[i+2][j+1].retType(),chessboard[i+2][j+1].retColor(),
                                                    chessboard[i+2][j+1].retPieceNo());
                            chessboard[i+2][j+1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(i+2<=7 && j-1<=7 && i+2>=0 && j-1>=0 && chessboard[i+2][j-1].retColor()!=turn && mate==1){
                            temp=chessboard[i+2][j-1];
                            chessboard[i+2][j-1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0){mate=0;}
                            chessboard[i][j].change(chessboard[i+2][j-1].retType(),chessboard[i+2][j-1].retColor(),
                                                    chessboard[i+2][j-1].retPieceNo());
                            chessboard[i+2][j-1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(i+1<=7 && j+2<=7 && i+1>=0 && j+2>=0 && chessboard[i+1][j+2].retColor()!=turn && mate==1){
                            temp=chessboard[i+1][j+2];
                            chessboard[i+1][j+2].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0){cout<<"3";mate=0;}
                            chessboard[i][j].change(chessboard[i+1][j+2].retType(),chessboard[i+1][j+2].retColor(),
                                                    chessboard[i+1][j+2].retPieceNo());
                            chessboard[i+1][j+2].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(i+1<=7 && j-2<=7 && i+1>=0 && j-2>=0 && chessboard[i+1][j-2].retColor()!=turn && mate==1){
                            temp=chessboard[i+1][j-2];
                            chessboard[i+1][j-2].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0){cout<<"4";mate=0;}
                            chessboard[i][j].change(chessboard[i+1][j-2].retType(),chessboard[i+1][j-2].retColor(),
                                                    chessboard[i+1][j-2].retPieceNo());
                            chessboard[i+1][j-2].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(i-2<=7 && j+1<=7 && i-2>=0 && j+1>=0 && chessboard[i-2][j+1].retColor()!=turn && mate==1){
                            temp=chessboard[i-2][j+1];
                            chessboard[i-2][j+1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0){cout<<"5";mate=0;}
                            chessboard[i][j].change(chessboard[i-2][j+1].retType(),chessboard[i-2][j+1].retColor(),
                                                    chessboard[i-2][j+1].retPieceNo());
                            chessboard[i-2][j+1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(i-2<=7 && j-1<=7 && i-2>=0 && j-1>=0 && chessboard[i-2][j-1].retColor()!=turn && mate==1){
                            temp=chessboard[i-2][j-1];
                            chessboard[i-2][j-1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0){cout<<"6";mate=0;}
                            chessboard[i][j].change(chessboard[i-2][j-1].retType(),chessboard[i-2][j-1].retColor(),
                                                    chessboard[i-2][j-1].retPieceNo());
                            chessboard[i-2][j-1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(i-1<=7 && j+2<=7 && i-1>=0 && j+2>=0 && chessboard[i-1][j+2].retColor()!=turn && mate==1){
                            temp=chessboard[i-1][j+2];
                            chessboard[i-1][j+2].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0){cout<<"7";mate=0;}
                            chessboard[i][j].change(chessboard[i-1][j+2].retType(),chessboard[i-1][j+2].retColor(),
                                                    chessboard[i-1][j+2].retPieceNo());
                            chessboard[i-1][j+2].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(i-1<=7 && j-2<=7 && i-1>=0 && j-2>=0 && chessboard[i-1][j-2].retColor()!=turn && mate==1){
                            temp=chessboard[i-1][j-2];
                            chessboard[i-1][j-2].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0){cout<<"8";mate=0;}
                            chessboard[i][j].change(chessboard[i-1][j-2].retType(),chessboard[i-1][j-2].retColor(),
                                                    chessboard[i-1][j-2].retPieceNo());
                            chessboard[i-1][j-2].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         break;
                case 'Q':k=i;l=j;
                         for(int p=0;p<2;p++){
                           m=1;
                           do{
                             k=i+(m*pow(-1,p));
                             m++;
                             if(chessboard[k][l].retColor()!=turn){
                                temp=chessboard[k][l];
                                chessboard[k][l].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                                chessboard[i][j].change('0','0',0);
                                if(check(chessboard,turn)==0)mate=0;
                                chessboard[i][j].change(chessboard[k][l].retType(),chessboard[k][l].retColor(),chessboard[k][l].retPieceNo());
                                chessboard[k][l].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                             }
                           }while(chessboard[k][l].retType()=='0' && mate==1 && k<=7 && l<=7 && k>=0 && l>=0);
                         }
                         k=i;l=j;
                         for(int p=0;p<2;p++){
                           m=1;
                           do{
                             l=j+(m*pow(-1,p));
                             m++;
                             if(chessboard[k][l].retColor()!=turn){
                                temp=chessboard[k][l];
                                chessboard[k][l].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                                chessboard[i][j].change('0','0',0);
                                if(check(chessboard,turn)==0)mate=0;
                                chessboard[i][j].change(chessboard[k][l].retType(),chessboard[k][l].retColor(),chessboard[k][l].retPieceNo());
                                chessboard[k][l].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                             }
                           }while(chessboard[k][l].retType()=='0' && mate==1 && k<=7 && l<=7 && k>=0 && l>=0);
                         }
                         k=i;l=j;
                         for(int p=0;p<2;p++){
                            for(int q=0;q<2;q++){
                               m=1;
                               do{
                                 k=i+(m*pow(-1,p));
                                 l=j+(m*pow(-1,q));
                                 m++;
                                 if(chessboard[k][l].retColor()!=turn){
                                    temp=chessboard[k][l];
                                    chessboard[k][l].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                            chessboard[i][j].retPieceNo());
                                    chessboard[i][j].change('0','0',0);
                                    if(check(chessboard,turn)==0)mate=0;
                                    chessboard[i][j].change(chessboard[k][l].retType(),chessboard[k][l].retColor(),
                                                            chessboard[k][l].retPieceNo());
                                    chessboard[k][l].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                 }
                               }while(chessboard[k][l].retType()=='0' && mate==1 && k<=7 && l<=7 && k>=0 && l>=0);
                            }

                         }
                         break;
                case 'K':if(chessboard[i+1][j+1].retColor()!=turn && mate==1 && i+1>=0 && i+1<=7 && j+1>=0 && j+1<=7){
                            temp=chessboard[i+1][j+1];
                            chessboard[i+1][j+1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0)mate=0;
                            chessboard[i][j].change(chessboard[i+1][j+1].retType(),chessboard[i+1][j+1].retColor(),
                                                    chessboard[i+1][j+1].retPieceNo());
                            chessboard[i+1][j+1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(chessboard[i+1][j-1].retColor()!=turn && mate==1 && i+1>=0 && i+1<=7 && j-1>=0 && j-1<=7){
                            temp=chessboard[i+1][j-1];
                            chessboard[i+1][j-1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0)mate=0;
                            chessboard[i][j].change(chessboard[i+1][j-1].retType(),chessboard[i+1][j-1].retColor(),
                                                    chessboard[i+1][j-1].retPieceNo());
                            chessboard[i+1][j-1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(chessboard[i-1][j+1].retColor()!=turn && mate==1 && i-1>=0 && i-1<=7 && j+1>=0 && j+1<=7){
                            temp=chessboard[i-1][j+1];
                            chessboard[i-1][j+1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0)mate=0;
                            chessboard[i][j].change(chessboard[i-1][j+1].retType(),chessboard[i-1][j+1].retColor(),
                                                    chessboard[i-1][j+1].retPieceNo());
                            chessboard[i-1][j+1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(chessboard[i-1][j-1].retColor()!=turn && mate==1 && i-1>=0 && i-1<=7 && j-1>=0 && j-1<=7){
                            temp=chessboard[i-1][j-1];
                            chessboard[i-1][j-1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                        chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0)mate=0;
                            chessboard[i][j].change(chessboard[i-1][j-1].retType(),chessboard[i-1][j-1].retColor(),
                                                    chessboard[i-1][j-1].retPieceNo());
                            chessboard[i-1][j-1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(chessboard[i+1][j].retColor()!=turn && mate==1){
                            temp=chessboard[i+1][j];
                            chessboard[i+1][j].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                      chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0)mate=0;
                            chessboard[i][j].change(chessboard[i+1][j].retType(),chessboard[i+1][j].retColor(),
                                                    chessboard[i+1][j].retPieceNo());
                            chessboard[i+1][j].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(chessboard[i][j+1].retColor()!=turn && mate==1){
                            temp=chessboard[i][j+1];
                            chessboard[i][j+1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                      chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0)mate=0;
                            chessboard[i][j].change(chessboard[i][j+1].retType(),chessboard[i][j+1].retColor(),
                                                    chessboard[i][j+1].retPieceNo());
                            chessboard[i][j+1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(chessboard[i-1][j].retColor()!=turn && mate==1){
                            temp=chessboard[i-1][j];
                            chessboard[i-1][j].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                      chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0)mate=0;
                            chessboard[i][j].change(chessboard[i-1][j].retType(),chessboard[i-1][j].retColor(),
                                                    chessboard[i-1][j].retPieceNo());
                            chessboard[i-1][j].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         if(chessboard[i][j-1].retColor()!=turn && mate==1){
                            temp=chessboard[i][j-1];
                            chessboard[i][j-1].change(chessboard[i][j].retType(),chessboard[i][j].retColor(),
                                                      chessboard[i][j].retPieceNo());
                            chessboard[i][j].change('0','0',0);
                            if(check(chessboard,turn)==0)mate=0;
                            chessboard[i][j].change(chessboard[i][j-1].retType(),chessboard[i][j-1].retColor(),
                                                    chessboard[i][j-1].retPieceNo());
                            chessboard[i][j-1].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                         }
                         break;
            }
         }
      }
   }
   return mate;
}

char promotion(char turn){
  Rectangle choice(683,34,200,20);
  choice.setColor(whiteCol);
  choice.setFill(true);
  Text choiceText(683,34,"What do u wanna promote ur pawn to?");
  if(turn=='w'){
    Rectangle horse(1053,144,80,80);
    horse.setColor(whiteCol);
    horse.setFill(true);
    Rectangle bishop(1053,304,80,80);
    bishop.setColor(whiteCol);
    bishop.setFill(true);
    Rectangle rook(1053,464,80,80);
    rook.setColor(whiteCol);
    rook.setFill(true);
    Rectangle queen(1053,624,80,80);
    queen.setColor(whiteCol);
    queen.setFill(true);
    Text horseText(1053,144,"KNIGHT");
    Text bishopText(1053,304,"BISHOP");
    Text rookText(1053,464,"ROOK");
    Text queenText(1053,624,"QUEEN");
    while(1){
    int click=getClick();
    if(click/65536<=1093 && click/65536>=1013 && click%65536<=224 && click%65536>=64)return 'H';
    if(click/65536<=1093 && click/65536>=1013 && click%65536<=384 && click%65536>=224)return 'B';
    if(click/65536<=1093 && click/65536>=1013 && click%65536<=544 && click%65536>=384)return 'R';
    if(click/65536<=1093 && click/65536>=1013 && click%65536<=704 && click%65536>=544)return 'Q';
    if(click/65536<=353 && click/65536>=273 && click%65536<=224 && click%65536>=64)return 'H';
    if(click/65536<=353 && click/65536>=273 && click%65536<=384 && click%65536>=224)return 'B';
    if(click/65536<=353 && click/65536>=273 && click%65536<=544 && click%65536>=384)return 'R';
    if(click/65536<=353 && click/65536>=273 && click%65536<=704 && click%65536>=544)return 'Q';
    }
    }
  if(turn=='b'){
    Rectangle horse(310,144,80,80);
    horse.setColor(whiteCol);
    horse.setFill(true);
    Rectangle bishop(310,304,80,80);
    bishop.setColor(whiteCol);
    bishop.setFill(true);
    Rectangle rook(310,464,80,80);
    rook.setColor(whiteCol);
    rook.setFill(true);
    Rectangle queen(310,624,80,80);
    queen.setColor(whiteCol);
    queen.setFill(true);
    Text horseText(310,144,"KNIGHT");
    Text bishopText(310,304,"BISHOP");
    Text rookText(310,464,"ROOK");
    Text queenText(310,624,"QUEEN");
    while(1){
    int click=getClick();
    if(click/65536<=1093 && click/65536>=1013 && click%65536<=224 && click%65536>=64)return 'H';
    if(click/65536<=1093 && click/65536>=1013 && click%65536<=384 && click%65536>=224)return 'B';
    if(click/65536<=1093 && click/65536>=1013 && click%65536<=544 && click%65536>=384)return 'R';
    if(click/65536<=1093 && click/65536>=1013 && click%65536<=704 && click%65536>=544)return 'Q';
    if(click/65536<=353 && click/65536>=273 && click%65536<=224 && click%65536>=64)return 'H';
    if(click/65536<=353 && click/65536>=273 && click%65536<=384 && click%65536>=224)return 'B';
    if(click/65536<=353 && click/65536>=273 && click%65536<=544 && click%65536>=384)return 'R';
    if(click/65536<=353 && click/65536>=273 && click%65536<=704 && click%65536>=544)return 'Q';
    }
    }
return '0';
}

main_program{
initCanvas("chess",1366,768);
Rectangle bg(683,384,1366,768);
bg.setColor(COLOR(177,100,29));
bg.setFill(true);
bg.imprint();
bg.hide();
Rectangle head(683,100,800,100);
head.setColor(COLOR(227,189,111));
head.setFill(true);
Text headText(683,100,"CHESS");

Rectangle playButton(1216,618,300,300);
playButton.setColor(COLOR(227,189,111));
playButton.setFill(true);

Rectangle exitButton(150,618,300,300);
exitButton.setColor(COLOR(227,189,111));
exitButton.setFill(true);

Text playText(1216,618,"PLAY");

Text exitText(150,618,"QUIT");
tile temp;
int location,locationX,locationY,to,toX,toY;
int killedByWhiteX=60,killedByWhiteY=60,killedByBlackX=1266,killedByBlackY=60;
int killMove=0,move=0;
int flagForCastlingWhite[2]={1,1};
int flagForCastlingBlack[2]={1,1};
tile killedBlack[16];
tile killedWhite[16];
int killedBlackIndex=0,killedWhiteIndex=0;
char currentColor='w';
do{
  location=getClick();
  locationX=location/65536;
  locationY=location%65536;
  if((locationX<=1366 && locationX>=1056) && (locationY<=768 && locationY>=468)){
  head.hide();
  headText.hide();
  playButton.hide();
  playText.hide();
  exitButton.hide();
  exitText.hide();
  Text loading(683,304,"LOADING.... Please Wait...");
  Rectangle chessBorder1(683,384,700,700);
  Rectangle chessBorder2(683,384,640,640);
  Rectangle blackTile(403,104,80,80);
  blackTile.setColor(COLOR(228,125,50));
  blackTile.setFill(true);
  Rectangle whiteTile(483,104,80,80);
  whiteTile.setColor(COLOR(248,217,194));
  whiteTile.setFill(true);
  for(int i=0;i<8;i++){
      for(int j=0;j<4;j++){
          blackTile.imprint();
          blackTile.move((pow(-1,i)*160),0);
          whiteTile.imprint();
          whiteTile.move((pow(-1,i)*160),0);
          }
      blackTile.move((pow(-1,i+1)*80),80);
      whiteTile.move((pow(-1,i+1)*240),80);
      }
  blackTile.hide();
  whiteTile.hide();
  char alphabet[][8]={"a","b","c","d","e","f","g","h"};
  for(int i=0;i<8;i++){
     Text gridX(403+(80*i),49,i+1);
     Text gridY(348,104+(80*i),alphabet[i]);
     gridX.imprint();
     gridY.imprint();
  }
  for(int i=0;i<8;i++){
     Text gridX(403+(80*i),719,i+1);
     Text gridY(1018,104+(80*i),alphabet[i]);
     gridX.imprint();
     gridY.imprint();
  }
  //WhitePawns
  Circle pawnWhiteHead1(centerX,centerY,8);
  pawnWhiteHead1.setColor(blackCol);
  Rectangle pawnWhiteStalk1(centerX,centerY,4,16);
  pawnWhiteStalk1.setColor(blackCol);
  Rectangle pawnWhiteBase1(centerX,centerY,20,4);
  pawnWhiteBase1.setColor(blackCol);
  movePawn(2,'a',pawnWhiteBase1,pawnWhiteStalk1,pawnWhiteHead1,'w');

  Circle pawnWhiteHead2(centerX,centerY,8);
  pawnWhiteHead2.setColor(blackCol);
  Rectangle pawnWhiteStalk2(centerX,centerY,4,16);
  pawnWhiteStalk2.setColor(blackCol);
  Rectangle pawnWhiteBase2(centerX,centerY,20,4);
  pawnWhiteBase2.setColor(blackCol);
  movePawn(2,'b',pawnWhiteBase2,pawnWhiteStalk2,pawnWhiteHead2,'w');

  Circle pawnWhiteHead3(centerX,centerY,8);
  pawnWhiteHead3.setColor(blackCol);
  Rectangle pawnWhiteStalk3(centerX,centerY,4,16);
  pawnWhiteStalk3.setColor(blackCol);
  Rectangle pawnWhiteBase3(centerX,centerY,20,4);
  pawnWhiteBase3.setColor(blackCol);
  movePawn(2,'c',pawnWhiteBase3,pawnWhiteStalk3,pawnWhiteHead3,'w');

  Circle pawnWhiteHead4(centerX,centerY,8);
  pawnWhiteHead4.setColor(blackCol);
  Rectangle pawnWhiteStalk4(centerX,centerY,4,16);
  pawnWhiteStalk4.setColor(blackCol);
  Rectangle pawnWhiteBase4(centerX,centerY,20,4);
  pawnWhiteBase4.setColor(blackCol);
  movePawn(2,'d',pawnWhiteBase4,pawnWhiteStalk4,pawnWhiteHead4,'w');

  Circle pawnWhiteHead5(centerX,centerY,8);
  pawnWhiteHead5.setColor(blackCol);
  Rectangle pawnWhiteStalk5(centerX,centerY,4,16);
  pawnWhiteStalk5.setColor(blackCol);
  Rectangle pawnWhiteBase5(centerX,centerY,20,4);
  pawnWhiteBase5.setColor(blackCol);
  movePawn(2,'e',pawnWhiteBase5,pawnWhiteStalk5,pawnWhiteHead5,'w');

  Circle pawnWhiteHead6(centerX,centerY,8);
  pawnWhiteHead6.setColor(blackCol);
  Rectangle pawnWhiteStalk6(centerX,centerY,4,16);
  pawnWhiteStalk6.setColor(blackCol);
  Rectangle pawnWhiteBase6(centerX,centerY,20,4);
  pawnWhiteBase6.setColor(blackCol);
  movePawn(2,'f',pawnWhiteBase6,pawnWhiteStalk6,pawnWhiteHead6,'w');

  Circle pawnWhiteHead7(centerX,centerY,8);
  pawnWhiteHead7.setColor(blackCol);
  Rectangle pawnWhiteStalk7(centerX,centerY,4,16);
  pawnWhiteStalk7.setColor(blackCol);
  Rectangle pawnWhiteBase7(centerX,centerY,20,4);
  pawnWhiteBase7.setColor(blackCol);
  movePawn(2,'g',pawnWhiteBase7,pawnWhiteStalk7,pawnWhiteHead7,'w');

  Circle pawnWhiteHead8(centerX,centerY,8);
  pawnWhiteHead8.setColor(blackCol);
  Rectangle pawnWhiteStalk8(centerX,centerY,4,16);
  pawnWhiteStalk8.setColor(blackCol);
  Rectangle pawnWhiteBase8(centerX,centerY,20,4);
  pawnWhiteBase8.setColor(blackCol);
  movePawn(2,'h',pawnWhiteBase8,pawnWhiteStalk8,pawnWhiteHead8,'w');

  //BlackPawns
  Circle pawnBlackHead1(centerX,centerY,8);
  pawnBlackHead1.setColor(blackCol);
  Rectangle pawnBlackStalk1(centerX,centerY,4,16);
  pawnBlackStalk1.setColor(blackCol);
  Rectangle pawnBlackBase1(centerX,centerY,20,4);
  pawnBlackBase1.setColor(blackCol);
  movePawn(7,'a',pawnBlackBase1,pawnBlackStalk1,pawnBlackHead1,'b');

  Circle pawnBlackHead2(centerX,centerY,8);
  pawnBlackHead2.setColor(blackCol);
  Rectangle pawnBlackStalk2(centerX,centerY,4,16);
  pawnBlackStalk2.setColor(blackCol);
  Rectangle pawnBlackBase2(centerX,centerY,20,4);
  pawnBlackBase2.setColor(blackCol);
  movePawn(7,'b',pawnBlackBase2,pawnBlackStalk2,pawnBlackHead2,'b');

  Circle pawnBlackHead3(centerX,centerY,8);
  pawnBlackHead3.setColor(blackCol);
  Rectangle pawnBlackStalk3(centerX,centerY,4,16);
  pawnBlackStalk3.setColor(blackCol);
  Rectangle pawnBlackBase3(centerX,centerY,20,4);
  pawnBlackBase3.setColor(blackCol);
  movePawn(7,'c',pawnBlackBase3,pawnBlackStalk3,pawnBlackHead3,'b');

  Circle pawnBlackHead4(centerX,centerY,8);
  pawnBlackHead4.setColor(blackCol);
  Rectangle pawnBlackStalk4(centerX,centerY,4,16);
  pawnBlackStalk4.setColor(blackCol);
  Rectangle pawnBlackBase4(centerX,centerY,20,4);
  pawnBlackBase4.setColor(blackCol);
  movePawn(7,'d',pawnBlackBase4,pawnBlackStalk4,pawnBlackHead4,'b');

  Circle pawnBlackHead5(centerX,centerY,8);
  pawnBlackHead5.setColor(blackCol);
  Rectangle pawnBlackStalk5(centerX,centerY,4,16);
  pawnBlackStalk5.setColor(blackCol);
  Rectangle pawnBlackBase5(centerX,centerY,20,4);
  pawnBlackBase5.setColor(blackCol);
  movePawn(7,'e',pawnBlackBase5,pawnBlackStalk5,pawnBlackHead5,'b');

  Circle pawnBlackHead6(centerX,centerY,8);
  pawnBlackHead6.setColor(blackCol);
  Rectangle pawnBlackStalk6(centerX,centerY,4,16);
  pawnBlackStalk6.setColor(blackCol);
  Rectangle pawnBlackBase6(centerX,centerY,20,4);
  pawnBlackBase6.setColor(blackCol);
  movePawn(7,'f',pawnBlackBase6,pawnBlackStalk6,pawnBlackHead6,'b');

  Circle pawnBlackHead7(centerX,centerY,8);
  pawnBlackHead7.setColor(blackCol);
  Rectangle pawnBlackStalk7(centerX,centerY,4,16);
  pawnBlackStalk7.setColor(blackCol);
  Rectangle pawnBlackBase7(centerX,centerY,20,4);
  pawnBlackBase7.setColor(blackCol);
  movePawn(7,'g',pawnBlackBase7,pawnBlackStalk7,pawnBlackHead7,'b');

  Circle pawnBlackHead8(centerX,centerY,8);
  pawnBlackHead8.setColor(blackCol);
  Rectangle pawnBlackStalk8(centerX,centerY,4,16);
  pawnBlackStalk8.setColor(blackCol);
  Rectangle pawnBlackBase8(centerX,centerY,20,4);
  pawnBlackBase8.setColor(blackCol);
  movePawn(7,'h',pawnBlackBase8,pawnBlackStalk8,pawnBlackHead8,'b');

  //WhiteRooks
  Rectangle rookWhiteBase1(centerX,centerY,40,50);
  Rectangle rookF1White1(centerX,centerY,8,8);
  Rectangle rookF2White1(centerX,centerY,8,8);
  Rectangle rookF3White1(centerX,centerY,8,8);
  Line l1White1(centerX-20,centerY-15,centerX+20,centerY-15);
  Line l2White1(centerX-20,centerY-10,centerX+20,centerY-10);
  moveRook(1,'a',rookWhiteBase1,rookF1White1,rookF2White1,rookF3White1,l1White1,l2White1,'w');

  Rectangle rookWhiteBase2(centerX,centerY,40,50);
  Rectangle rookF1White2(centerX,centerY,8,8);
  Rectangle rookF2White2(centerX,centerY,8,8);
  Rectangle rookF3White2(centerX,centerY,8,8);
  Line l1White2(centerX-20,centerY-15,centerX+20,centerY-15);
  Line l2White2(centerX-20,centerY-10,centerX+20,centerY-10);
  moveRook(1,'h',rookWhiteBase2,rookF1White2,rookF2White2,rookF3White2,l1White2,l2White2,'w');

  //BlackRooks
  Rectangle rookBlackBase1(centerX,centerY,40,50);
  Rectangle rookF1Black1(centerX,centerY,8,8);
  Rectangle rookF2Black1(centerX,centerY,8,8);
  Rectangle rookF3Black1(centerX,centerY,8,8);
  Line l1Black1(centerX-20,centerY-15,centerX+20,centerY-15);
  Line l2Black1(centerX-20,centerY-10,centerX+20,centerY-10);
  moveRook(8,'a',rookBlackBase1,rookF1Black1,rookF2Black1,rookF3Black1,l1Black1,l2Black1,'b');

  Rectangle rookBlackBase2(centerX,centerY,40,50);
  Rectangle rookF1Black2(centerX,centerY,8,8);
  Rectangle rookF2Black2(centerX,centerY,8,8);
  Rectangle rookF3Black2(centerX,centerY,8,8);
  Line l1Black2(centerX-20,centerY-15,centerX+20,centerY-15);
  Line l2Black2(centerX-20,centerY-10,centerX+20,centerY-10);
  moveRook(8,'h',rookBlackBase2,rookF1Black2,rookF2Black2,rookF3Black2,l1Black2,l2Black2,'b');

  //WhiteHorses
  Rectangle horseWhiteStalk1(centerX,centerY,16,30);
  Rectangle horseWhiteHair1(centerX,centerY,8,22);
  Rectangle horseFace1White1(centerX,centerY,10,18);
  Rectangle horseFace2White1(centerX,centerY,20,14);
  Rectangle horseWhiteBase1(centerX,centerY,30,8);
  moveHorse(1,'b',horseWhiteStalk1,horseWhiteHair1,horseFace1White1,horseFace2White1,horseWhiteBase1,'w');

  Rectangle horseWhiteStalk2(centerX,centerY,16,30);
  Rectangle horseWhiteHair2(centerX,centerY,8,22);
  Rectangle horseFace1White2(centerX,centerY,10,18);
  Rectangle horseFace2White2(centerX,centerY,20,14);
  Rectangle horseWhiteBase2(centerX,centerY,30,8);
  moveHorse(1,'g',horseWhiteStalk2,horseWhiteHair2,horseFace1White2,horseFace2White2,horseWhiteBase2,'w');

  //BlackHorses
  Rectangle horseBlackStalk1(centerX,centerY,16,30);
  Rectangle horseBlackHair1(centerX,centerY,8,22);
  Rectangle horseFace1Black1(centerX,centerY,10,18);
  Rectangle horseFace2Black1(centerX,centerY,20,14);
  Rectangle horseBlackBase1(centerX,centerY,30,8);
  moveHorse(8,'b',horseBlackStalk1,horseBlackHair1,horseFace1Black1,horseFace2Black1,horseBlackBase1,'b');

  Rectangle horseBlackStalk2(centerX,centerY,16,30);
  Rectangle horseBlackHair2(centerX,centerY,8,22);
  Rectangle horseFace1Black2(centerX,centerY,10,18);
  Rectangle horseFace2Black2(centerX,centerY,20,14);
  Rectangle horseBlackBase2(centerX,centerY,30,8);
  moveHorse(8,'g',horseBlackStalk2,horseBlackHair2,horseFace1Black2,horseFace2Black2,horseBlackBase2,'b');

  //WhiteBishops
  Circle bishopC1White1(centerX,centerY,4);
  Circle bishopC2White1(centerX,centerY,6);
  Circle bishopC3White1(centerX,centerY,8);
  Rectangle bishopWhiteStalk1(centerX,centerY,8,26);
  Rectangle bishopWhiteBase1(centerX,centerY,30,8);
  moveBishop(1,'c',bishopC1White1,bishopC2White1,bishopC3White1,bishopWhiteStalk1,bishopWhiteBase1,'w');

  Circle bishopC1White2(centerX,centerY,4);
  Circle bishopC2White2(centerX,centerY,6);
  Circle bishopC3White2(centerX,centerY,8);
  Rectangle bishopWhiteStalk2(centerX,centerY,8,26);
  Rectangle bishopWhiteBase2(centerX,centerY,30,8);
  moveBishop(1,'f',bishopC1White2,bishopC2White2,bishopC3White2,bishopWhiteStalk2,bishopWhiteBase2,'w');

  //BlackBishops
  Circle bishopC1Black1(centerX,centerY,4);
  Circle bishopC2Black1(centerX,centerY,6);
  Circle bishopC3Black1(centerX,centerY,8);
  Rectangle bishopBlackStalk1(centerX,centerY,8,26);
  Rectangle bishopBlackBase1(centerX,centerY,30,8);
  moveBishop(8,'c',bishopC1Black1,bishopC2Black1,bishopC3Black1,bishopBlackStalk1,bishopBlackBase1,'b');

  Circle bishopC1Black2(centerX,centerY,4);
  Circle bishopC2Black2(centerX,centerY,6);
  Circle bishopC3Black2(centerX,centerY,8);
  Rectangle bishopBlackStalk2(centerX,centerY,8,26);
  Rectangle bishopBlackBase2(centerX,centerY,30,8);
  moveBishop(8,'f',bishopC1Black2,bishopC2Black2,bishopC3Black2,bishopBlackStalk2,bishopBlackBase2,'b');

  //WhiteQueen
  Rectangle queenWhiteBase(centerX,centerY,30,10);
  Line queenL1White(centerX-15,centerY+25,centerX-10,centerY+20);
  Line queenL2White(centerX+15,centerY+25,centerX+10,centerY+20);
  Line queenL3White(centerX-10,centerY+20,centerX+10,centerY+20);
  Line queenL4White(centerX-10,centerY+20,centerX-15,centerY);
  Line queenL5White(centerX-15,centerY,centerX-5,centerY+15);
  Line queenL6White(centerX-5,centerY+15,centerX,centerY-5);
  Line queenL7White(centerX,centerY-5,centerX+5,centerY+15);
  Line queenL8White(centerX+5,centerY+15,centerX+15,centerY);
  Line queenL9White(centerX+15,centerY,centerX+10,centerY+20);
  Circle queenC1White(centerX,centerY,6);
  Circle queenC2White(centerX,centerY,6);
  Circle queenC3White(centerX,centerY,6);
  moveQueen(1,'d',queenWhiteBase,queenL1White,queenL2White,queenL3White,queenL4White,queenL5White,queenL6White
  ,queenL7White,queenL8White,queenL9White,queenC1White,queenC2White,queenC3White,'w');

  //BlackQueen
  Rectangle queenBlackBase(centerX,centerY,30,10);
  Line queenL1Black(centerX-15,centerY+25,centerX-10,centerY+20);
  Line queenL2Black(centerX+15,centerY+25,centerX+10,centerY+20);
  Line queenL3Black(centerX-10,centerY+20,centerX+10,centerY+20);
  Line queenL4Black(centerX-10,centerY+20,centerX-15,centerY);
  Line queenL5Black(centerX-15,centerY,centerX-5,centerY+15);
  Line queenL6Black(centerX-5,centerY+15,centerX,centerY-5);
  Line queenL7Black(centerX,centerY-5,centerX+5,centerY+15);
  Line queenL8Black(centerX+5,centerY+15,centerX+15,centerY);
  Line queenL9Black(centerX+15,centerY,centerX+10,centerY+20);
  Circle queenC1Black(centerX,centerY,6);
  Circle queenC2Black(centerX,centerY,6);
  Circle queenC3Black(centerX,centerY,6);
  moveQueen(8,'d',queenBlackBase,queenL1Black,queenL2Black,queenL3Black,queenL4Black,queenL5Black,queenL6Black
            ,queenL7Black,queenL8Black,queenL9Black,queenC1Black,queenC2Black,queenC3Black,'b');

  //WhiteKing
  Circle kingC1White(centerX,centerY,16);
  Circle kingC2White(centerX,centerY,16);
  Line kingL1White(centerX-16,centerY-16,centerX-16,centerY+16);
  Line kingL2White(centerX-32,centerY,centerX,centerY);
  Line kingL3White(centerX+16,centerY-16,centerX+16,centerY+16);
  Line kingL4White(centerX,centerY,centerX+32,centerY);
  Rectangle kingBase1White(centerX,centerY,40,10);
  Rectangle kingBase2White(centerX,centerY,40,10);
  Rectangle kingWhiteHead(centerX,centerY,8,12);
  Line kingL5White(centerX,centerY-22,centerX,centerY-32);
  Line kingL6White(centerX-5,centerY-27,centerX+5,centerY-27);
  moveKing(1,'e',kingC1White,kingC2White,kingL1White,kingL2White,kingL3White,kingL4White,kingBase1White
           ,kingBase2White,kingWhiteHead,kingL5White,kingL6White,'w');

  //BlackKing
  Circle kingC1Black(centerX,centerY,16);
  Circle kingC2Black(centerX,centerY,16);
  Line kingL1Black(centerX-16,centerY-16,centerX-16,centerY+16);
  Line kingL2Black(centerX-32,centerY,centerX,centerY);
  Line kingL3Black(centerX+16,centerY-16,centerX+16,centerY+16);
  Line kingL4Black(centerX,centerY,centerX+32,centerY);
  Rectangle kingBase1Black(centerX,centerY,40,10);
  Rectangle kingBase2Black(centerX,centerY,40,10);
  Rectangle kingBlackHead(centerX,centerY,8,12);
  Line kingL5Black(centerX,centerY-22,centerX,centerY-32);
  Line kingL6Black(centerX-5,centerY-27,centerX+5,centerY-27);
  moveKing(8,'e',kingC1Black,kingC2Black,kingL1Black,kingL2Black,kingL3Black,kingL4Black,kingBase1Black
           ,kingBase2Black,kingBlackHead,kingL5Black,kingL6Black,'b');
  loading.hide();
  tile chessboard[8][8];
  Rectangle selected(centerX,centerY,75,75);
  selected.setColor(blackCol);
  selected.hide();
  setBoard(chessboard);

  Text whiteHorse1(683,384,"KNIGHT");whiteHorse1.hide();
  Text whiteHorse2(683,384,"KNIGHT");whiteHorse2.hide();
  Text whiteHorse3(683,384,"KNIGHT");whiteHorse3.hide();
  Text whiteHorse4(683,384,"KNIGHT");whiteHorse4.hide();
  Text whiteHorse5(683,384,"KNIGHT");whiteHorse5.hide();
  Text whiteHorse6(683,384,"KNIGHT");whiteHorse6.hide();
  Text whiteHorse7(683,384,"KNIGHT");whiteHorse7.hide();
  Text whiteHorse8(683,384,"KNIGHT");whiteHorse8.hide();

  Text whiteBishop1(683,384,"BISHOP");whiteBishop1.hide();
  Text whiteBishop2(683,384,"BISHOP");whiteBishop2.hide();
  Text whiteBishop3(683,384,"BISHOP");whiteBishop3.hide();
  Text whiteBishop4(683,384,"BISHOP");whiteBishop4.hide();
  Text whiteBishop5(683,384,"BISHOP");whiteBishop5.hide();
  Text whiteBishop6(683,384,"BISHOP");whiteBishop6.hide();
  Text whiteBishop7(683,384,"BISHOP");whiteBishop7.hide();
  Text whiteBishop8(683,384,"BISHOP");whiteBishop8.hide();

  Text whiteRook1(683,384,"ROOK");whiteRook1.hide();
  Text whiteRook2(683,384,"ROOK");whiteRook2.hide();
  Text whiteRook3(683,384,"ROOK");whiteRook3.hide();
  Text whiteRook4(683,384,"ROOK");whiteRook4.hide();
  Text whiteRook5(683,384,"ROOK");whiteRook5.hide();
  Text whiteRook6(683,384,"ROOK");whiteRook6.hide();
  Text whiteRook7(683,384,"ROOK");whiteRook7.hide();
  Text whiteRook8(683,384,"ROOK");whiteRook8.hide();

  Text whiteQueen1(683,384,"QUEEN");whiteQueen1.hide();
  Text whiteQueen2(683,384,"QUEEN");whiteQueen2.hide();
  Text whiteQueen3(683,384,"QUEEN");whiteQueen3.hide();
  Text whiteQueen4(683,384,"QUEEN");whiteQueen4.hide();
  Text whiteQueen5(683,384,"QUEEN");whiteQueen5.hide();
  Text whiteQueen6(683,384,"QUEEN");whiteQueen6.hide();
  Text whiteQueen7(683,384,"QUEEN");whiteQueen7.hide();
  Text whiteQueen8(683,384,"QUEEN");whiteQueen8.hide();

  Text blackHorse1(683,384,"KNIGHT");blackHorse1.hide();
  Text blackHorse2(683,384,"KNIGHT");blackHorse2.hide();
  Text blackHorse3(683,384,"KNIGHT");blackHorse3.hide();
  Text blackHorse4(683,384,"KNIGHT");blackHorse4.hide();
  Text blackHorse5(683,384,"KNIGHT");blackHorse5.hide();
  Text blackHorse6(683,384,"KNIGHT");blackHorse6.hide();
  Text blackHorse7(683,384,"KNIGHT");blackHorse7.hide();
  Text blackHorse8(683,384,"KNIGHT");blackHorse8.hide();

  Text blackBishop1(683,384,"BISHOP");blackBishop1.hide();
  Text blackBishop2(683,384,"BISHOP");blackBishop2.hide();
  Text blackBishop3(683,384,"BISHOP");blackBishop3.hide();
  Text blackBishop4(683,384,"BISHOP");blackBishop4.hide();
  Text blackBishop5(683,384,"BISHOP");blackBishop5.hide();
  Text blackBishop6(683,384,"BISHOP");blackBishop6.hide();
  Text blackBishop7(683,384,"BISHOP");blackBishop7.hide();
  Text blackBishop8(683,384,"BISHOP");blackBishop8.hide();

  Text blackRook1(683,384,"ROOK");blackRook1.hide();
  Text blackRook2(683,384,"ROOK");blackRook2.hide();
  Text blackRook3(683,384,"ROOK");blackRook3.hide();
  Text blackRook4(683,384,"ROOK");blackRook4.hide();
  Text blackRook5(683,384,"ROOK");blackRook5.hide();
  Text blackRook6(683,384,"ROOK");blackRook6.hide();
  Text blackRook7(683,384,"ROOK");blackRook7.hide();
  Text blackRook8(683,384,"ROOK");blackRook8.hide();

  Text blackQueen1(683,384,"QUEEN");blackQueen1.hide();
  Text blackQueen2(683,384,"QUEEN");blackQueen2.hide();
  Text blackQueen3(683,384,"QUEEN");blackQueen3.hide();
  Text blackQueen4(683,384,"QUEEN");blackQueen4.hide();
  Text blackQueen5(683,384,"QUEEN");blackQueen5.hide();
  Text blackQueen6(683,384,"QUEEN");blackQueen6.hide();
  Text blackQueen7(683,384,"QUEEN");blackQueen7.hide();
  Text blackQueen8(683,384,"QUEEN");blackQueen8.hide();

  do{
    if(temp.retPieceNo()<=2 || temp.retType()=='P'){
    if(killMove==1 && temp.retColor()=='b'){
       switch(temp.retType()){
          case 'P':if(temp.retPieceNo()==1){
                      moveKilledPawn(killedByWhiteX,killedByWhiteY,pawnBlackBase1,pawnBlackStalk1,pawnBlackHead1);
                      }
                   if(temp.retPieceNo()==2){
                      moveKilledPawn(killedByWhiteX,killedByWhiteY,pawnBlackBase2,pawnBlackStalk2,pawnBlackHead2);
                      }
                   if(temp.retPieceNo()==3){
                      moveKilledPawn(killedByWhiteX,killedByWhiteY,pawnBlackBase3,pawnBlackStalk3,pawnBlackHead3);
                      }
                   if(temp.retPieceNo()==4){
                      moveKilledPawn(killedByWhiteX,killedByWhiteY,pawnBlackBase4,pawnBlackStalk4,pawnBlackHead4);
                      }
                   if(temp.retPieceNo()==5){
                      moveKilledPawn(killedByWhiteX,killedByWhiteY,pawnBlackBase5,pawnBlackStalk5,pawnBlackHead5);
                      }
                   if(temp.retPieceNo()==6){
                      moveKilledPawn(killedByWhiteX,killedByWhiteY,pawnBlackBase6,pawnBlackStalk6,pawnBlackHead6);
                      }
                   if(temp.retPieceNo()==7){
                      moveKilledPawn(killedByWhiteX,killedByWhiteY,pawnBlackBase7,pawnBlackStalk7,pawnBlackHead7);
                      }
                   if(temp.retPieceNo()==8){
                      moveKilledPawn(killedByWhiteX,killedByWhiteY,pawnBlackBase8,pawnBlackStalk8,pawnBlackHead8);
                      }
                   break;
          case 'R':if(temp.retPieceNo()==1){
                      moveKilledRook(killedByWhiteX,killedByWhiteY,rookBlackBase1,rookF1Black1,rookF2Black1,
                                     rookF3Black1,l1Black1,l2Black1);
                      }
                   if(temp.retPieceNo()==2){
                      moveKilledRook(killedByWhiteX,killedByWhiteY,rookBlackBase2,rookF1Black2,rookF2Black2,
                                     rookF3Black2,l1Black2,l2Black2);
                      }
                   break;
          case 'B':if(temp.retPieceNo()==1){
                      moveKilledBishop(killedByWhiteX,killedByWhiteY,bishopC1Black1,bishopC2Black1,bishopC3Black1,
                                       bishopBlackStalk1,bishopBlackBase1);
                      }
                   if(temp.retPieceNo()==2){
                      moveKilledBishop(killedByWhiteX,killedByWhiteY,bishopC1Black2,bishopC2Black2,bishopC3Black2,
                                       bishopBlackStalk2,bishopBlackBase2);
                      }
                   break;
          case 'H':if(temp.retPieceNo()==1){
                      moveKilledHorse(killedByWhiteX,killedByWhiteY,horseBlackStalk1,horseBlackHair1,horseFace1Black1,
                                      horseFace2Black1,horseBlackBase1,'w');
                      }
                   if(temp.retPieceNo()==2){
                      moveKilledHorse(killedByWhiteX,killedByWhiteY,horseBlackStalk2,horseBlackHair2,horseFace1Black2,
                                      horseFace2Black2,horseBlackBase2,'w');
                      }
                   break;
          case 'Q':if(temp.retPieceNo()==1){
                     moveKilledQueen(killedByWhiteX,killedByWhiteY,queenBlackBase,queenL1Black,queenL2Black,queenL3Black,
                                     queenL4Black,queenL5Black,queenL6Black,queenL7Black,queenL8Black,queenL9Black,
                                     queenC1Black,queenC2Black,queenC3Black);
                   }
                   break;
          case 'K':if(temp.retPieceNo()==1){
                     moveKilledKing(killedByWhiteX,killedByWhiteY,kingC1Black,kingC2Black,kingL1Black,kingL2Black,kingL3Black,
                                    kingL4Black,kingBase1Black,kingBase2Black,kingBlackHead,kingL5Black,kingL6Black);
                   }
                   break;
          }
       if(killedByWhiteY==700){killedByWhiteY=60;killedByWhiteX=140;}
       else{killedByWhiteY+=80;}
       killedBlack[killedBlackIndex]=temp;
       killedBlackIndex++;
       }
    if(killMove==1 && temp.retColor()=='w'){
       switch(temp.retType()){
          case 'P':if(temp.retPieceNo()==1){
                      moveKilledPawn(killedByBlackX,killedByBlackY,pawnWhiteBase1,pawnWhiteStalk1,pawnWhiteHead1);
                      }
                   if(temp.retPieceNo()==2){
                      moveKilledPawn(killedByBlackX,killedByBlackY,pawnWhiteBase2,pawnWhiteStalk2,pawnWhiteHead2);
                      }
                   if(temp.retPieceNo()==3){
                      moveKilledPawn(killedByBlackX,killedByBlackY,pawnWhiteBase3,pawnWhiteStalk3,pawnWhiteHead3);
                      }
                   if(temp.retPieceNo()==4){
                      moveKilledPawn(killedByBlackX,killedByBlackY,pawnWhiteBase4,pawnWhiteStalk4,pawnWhiteHead4);
                      }
                   if(temp.retPieceNo()==5){
                      moveKilledPawn(killedByBlackX,killedByBlackY,pawnWhiteBase5,pawnWhiteStalk5,pawnWhiteHead5);
                      }
                   if(temp.retPieceNo()==6){
                      moveKilledPawn(killedByBlackX,killedByBlackY,pawnWhiteBase6,pawnWhiteStalk6,pawnWhiteHead6);
                      }
                   if(temp.retPieceNo()==7){
                      moveKilledPawn(killedByBlackX,killedByBlackY,pawnWhiteBase7,pawnWhiteStalk7,pawnWhiteHead7);
                      }
                   if(temp.retPieceNo()==8){
                      moveKilledPawn(killedByBlackX,killedByBlackY,pawnWhiteBase8,pawnWhiteStalk8,pawnWhiteHead8);
                      }
                   break;
          case 'R':if(temp.retPieceNo()==1){
                      moveKilledRook(killedByBlackX,killedByBlackY,rookWhiteBase1,rookF1White1,rookF2White1,
                                     rookF3White1,l1White1,l2White1);
                      }
                   if(temp.retPieceNo()==2){
                      moveKilledRook(killedByBlackX,killedByBlackY,rookWhiteBase2,rookF1White2,rookF2White2,
                                     rookF3White2,l1White2,l2White2);
                      }
                   break;
          case 'B':if(temp.retPieceNo()==1){
                      moveKilledBishop(killedByBlackX,killedByBlackY,bishopC1White1,bishopC2White1,bishopC3White1,
                                       bishopWhiteStalk1,bishopWhiteBase1);
                      }
                   if(temp.retPieceNo()==2){
                      moveKilledBishop(killedByBlackX,killedByBlackY,bishopC1White2,bishopC2White2,bishopC3White2,
                                       bishopWhiteStalk2,bishopWhiteBase2);
                      }
                   break;
          case 'H':if(temp.retPieceNo()==1){
                      moveKilledHorse(killedByBlackX,killedByBlackY,horseWhiteStalk1,horseWhiteHair1,horseFace1White1,
                                      horseFace2White1,horseWhiteBase1,'b');
                      }
                   if(temp.retPieceNo()==2){
                      moveKilledHorse(killedByBlackX,killedByBlackY,horseWhiteStalk2,horseWhiteHair2,horseFace1White2,
                                      horseFace2White2,horseWhiteBase2,'b');
                      }
                   break;
          case 'Q':if(temp.retPieceNo()==1){
                     moveKilledQueen(killedByBlackX,killedByBlackY,queenWhiteBase,queenL1White,queenL2White,queenL3White,
                                     queenL4White,queenL5White,queenL6White,queenL7White,queenL8White,queenL9White,
                                     queenC1White,queenC2White,queenC3White);
                   }
                   break;
          case 'K':if(temp.retPieceNo()==1){
                     moveKilledKing(killedByBlackX,killedByBlackY,kingC1White,kingC2White,kingL1White,kingL2White,kingL3White,
                                    kingL4White,kingBase1White,kingBase2White,kingWhiteHead,kingL5White,kingL6White);
                   }
                   break;
          }
       if(killedByBlackY==700){killedByBlackY=60;killedByBlackX=1186;}
       else{killedByBlackY+=80;}
       killedWhite[killedWhiteIndex]=temp;
       killedWhiteIndex++;
       }
    }
    else{
      if(killMove==1){
         if(currentColor=='w')
         switch(temp.retType()){
            case 'R':if(temp.retPieceNo()==3){
                        pawnWhiteBase1.hide();
                        pawnWhiteStalk1.hide();
                        pawnWhiteHead1.hide();
                        whiteRook1.hide();
                        }
                     if(temp.retPieceNo()==4){
                        pawnWhiteBase2.hide();
                        pawnWhiteStalk2.hide();
                        pawnWhiteHead2.hide();
                        whiteRook2.hide();
                        }
                     if(temp.retPieceNo()==5){
                        pawnWhiteBase3.hide();
                        pawnWhiteStalk3.hide();
                        pawnWhiteHead3.hide();
                        whiteRook3.hide();
                        }
                     if(temp.retPieceNo()==6){
                        pawnWhiteBase4.hide();
                        pawnWhiteStalk4.hide();
                        pawnWhiteHead4.hide();
                        whiteRook4.hide();
                        }
                     if(temp.retPieceNo()==7){
                        pawnWhiteBase5.hide();
                        pawnWhiteStalk5.hide();
                        pawnWhiteHead5.hide();
                        whiteRook5.hide();
                        }
                     if(temp.retPieceNo()==8){
                        pawnWhiteBase6.hide();
                        pawnWhiteStalk6.hide();
                        pawnWhiteHead6.hide();
                        whiteRook6.hide();
                        }
                     if(temp.retPieceNo()==9){
                        pawnWhiteBase7.hide();
                        pawnWhiteStalk7.hide();
                        pawnWhiteHead7.hide();
                        whiteRook7.hide();
                        }
                     if(temp.retPieceNo()==10){
                        pawnWhiteBase8.hide();
                        pawnWhiteStalk8.hide();
                        pawnWhiteHead8.hide();
                        whiteRook8.hide();
                        }
                     break;
            case 'B':if(temp.retPieceNo()==3){
                        pawnWhiteBase1.hide();
                        pawnWhiteStalk1.hide();
                        pawnWhiteHead1.hide();
                        whiteBishop1.hide();
                        }
                     if(temp.retPieceNo()==4){
                        pawnWhiteBase2.hide();
                        pawnWhiteStalk2.hide();
                        pawnWhiteHead2.hide();
                        whiteBishop2.hide();
                        }
                     if(temp.retPieceNo()==5){
                        pawnWhiteBase3.hide();
                        pawnWhiteStalk3.hide();
                        pawnWhiteHead3.hide();
                        whiteBishop3.hide();
                        }
                     if(temp.retPieceNo()==6){
                        pawnWhiteBase4.hide();
                        pawnWhiteStalk4.hide();
                        pawnWhiteHead4.hide();
                        whiteBishop4.hide();
                        }
                     if(temp.retPieceNo()==7){
                        pawnWhiteBase5.hide();
                        pawnWhiteStalk5.hide();
                        pawnWhiteHead5.hide();
                        whiteBishop5.hide();
                        }
                     if(temp.retPieceNo()==8){
                        pawnWhiteBase6.hide();
                        pawnWhiteStalk6.hide();
                        pawnWhiteHead6.hide();
                        whiteBishop6.hide();
                        }
                     if(temp.retPieceNo()==9){
                        pawnWhiteBase7.hide();
                        pawnWhiteStalk7.hide();
                        pawnWhiteHead7.hide();
                        whiteBishop7.hide();
                        }
                     if(temp.retPieceNo()==10){
                        pawnWhiteBase8.hide();
                        pawnWhiteStalk8.hide();
                        pawnWhiteHead8.hide();
                        whiteBishop8.hide();
                        }
                     break;
            case 'H':if(temp.retPieceNo()==3){
                        pawnWhiteBase1.hide();
                        pawnWhiteStalk1.hide();
                        pawnWhiteHead1.hide();
                        whiteHorse1.hide();
                        }
                     if(temp.retPieceNo()==4){
                        pawnWhiteBase2.hide();
                        pawnWhiteStalk2.hide();
                        pawnWhiteHead2.hide();
                        whiteHorse2.hide();
                        }
                     if(temp.retPieceNo()==5){
                        pawnWhiteBase3.hide();
                        pawnWhiteStalk3.hide();
                        pawnWhiteHead3.hide();
                        whiteHorse3.hide();
                        }
                     if(temp.retPieceNo()==6){
                        pawnWhiteBase4.hide();
                        pawnWhiteStalk4.hide();
                        pawnWhiteHead4.hide();
                        whiteHorse4.hide();
                        }
                     if(temp.retPieceNo()==7){
                        pawnWhiteBase5.hide();
                        pawnWhiteStalk5.hide();
                        pawnWhiteHead5.hide();
                        whiteHorse5.hide();
                        }
                     if(temp.retPieceNo()==8){
                        pawnWhiteBase6.hide();
                        pawnWhiteStalk6.hide();
                        pawnWhiteHead6.hide();
                        whiteHorse6.hide();
                        }
                     if(temp.retPieceNo()==9){
                        pawnWhiteBase7.hide();
                        pawnWhiteStalk7.hide();
                        pawnWhiteHead7.hide();
                        whiteHorse7.hide();
                        }
                     if(temp.retPieceNo()==10){
                        pawnWhiteBase8.hide();
                        pawnWhiteStalk8.hide();
                        pawnWhiteHead8.hide();
                        whiteHorse8.hide();
                        }
                     break;
            case 'Q':if(temp.retPieceNo()==3){
                        pawnWhiteBase1.hide();
                        pawnWhiteStalk1.hide();
                        pawnWhiteHead1.hide();
                        whiteQueen1.hide();
                        }
                     if(temp.retPieceNo()==4){
                        pawnWhiteBase2.hide();
                        pawnWhiteStalk2.hide();
                        pawnWhiteHead2.hide();
                        whiteQueen2.hide();
                        }
                     if(temp.retPieceNo()==5){
                        pawnWhiteBase3.hide();
                        pawnWhiteStalk3.hide();
                        pawnWhiteHead3.hide();
                        whiteQueen3.hide();
                        }
                     if(temp.retPieceNo()==6){
                        pawnWhiteBase4.hide();
                        pawnWhiteStalk4.hide();
                        pawnWhiteHead4.hide();
                        whiteQueen4.hide();
                        }
                     if(temp.retPieceNo()==7){
                        pawnWhiteBase5.hide();
                        pawnWhiteStalk5.hide();
                        pawnWhiteHead5.hide();
                        whiteQueen5.hide();
                        }
                     if(temp.retPieceNo()==8){
                        pawnWhiteBase6.hide();
                        pawnWhiteStalk6.hide();
                        pawnWhiteHead6.hide();
                        whiteQueen6.hide();
                        }
                     if(temp.retPieceNo()==9){
                        pawnWhiteBase7.hide();
                        pawnWhiteStalk7.hide();
                        pawnWhiteHead7.hide();
                        whiteQueen7.hide();
                        }
                     if(temp.retPieceNo()==10){
                        pawnWhiteBase8.hide();
                        pawnWhiteStalk8.hide();
                        pawnWhiteHead8.hide();
                        whiteQueen8.hide();
                        }
                     break;
            }
        if(currentColor=='b')
          switch(temp.retType()){
            case 'R':if(temp.retPieceNo()==3){
                        pawnBlackBase1.hide();
                        pawnBlackStalk1.hide();
                        pawnBlackHead1.hide();
                        blackRook1.hide();
                        }
                     if(temp.retPieceNo()==4){
                        pawnBlackBase2.hide();
                        pawnBlackStalk2.hide();
                        pawnBlackHead2.hide();
                        blackRook2.hide();
                        }
                     if(temp.retPieceNo()==5){
                        pawnBlackBase3.hide();
                        pawnBlackStalk3.hide();
                        pawnBlackHead3.hide();
                        blackRook3.hide();
                        }
                     if(temp.retPieceNo()==6){
                        pawnBlackBase4.hide();
                        pawnBlackStalk4.hide();
                        pawnBlackHead4.hide();
                        blackRook4.hide();
                        }
                     if(temp.retPieceNo()==7){
                        pawnBlackBase5.hide();
                        pawnBlackStalk5.hide();
                        pawnBlackHead5.hide();
                        blackRook5.hide();
                        }
                     if(temp.retPieceNo()==8){
                        pawnBlackBase6.hide();
                        pawnBlackStalk6.hide();
                        pawnBlackHead6.hide();
                        blackRook6.hide();
                        }
                     if(temp.retPieceNo()==9){
                        pawnBlackBase7.hide();
                        pawnBlackStalk7.hide();
                        pawnBlackHead7.hide();
                        blackRook7.hide();
                        }
                     if(temp.retPieceNo()==10){
                        pawnBlackBase8.hide();
                        pawnBlackStalk8.hide();
                        pawnBlackHead8.hide();
                        blackRook8.hide();
                        }
                     break;
            case 'B':if(temp.retPieceNo()==3){
                        pawnBlackBase1.hide();
                        pawnBlackStalk1.hide();
                        pawnBlackHead1.hide();
                        blackBishop1.hide();
                        }
                     if(temp.retPieceNo()==4){
                        pawnBlackBase2.hide();
                        pawnBlackStalk2.hide();
                        pawnBlackHead2.hide();
                        blackBishop2.hide();
                        }
                     if(temp.retPieceNo()==5){
                        pawnBlackBase3.hide();
                        pawnBlackStalk3.hide();
                        pawnBlackHead3.hide();
                        blackBishop3.hide();
                        }
                     if(temp.retPieceNo()==6){
                        pawnBlackBase4.hide();
                        pawnBlackStalk4.hide();
                        pawnBlackHead4.hide();
                        blackBishop4.hide();
                        }
                     if(temp.retPieceNo()==7){
                        pawnBlackBase5.hide();
                        pawnBlackStalk5.hide();
                        pawnBlackHead5.hide();
                        blackBishop5.hide();
                        }
                     if(temp.retPieceNo()==8){
                        pawnBlackBase6.hide();
                        pawnBlackStalk6.hide();
                        pawnBlackHead6.hide();
                        blackBishop6.hide();
                        }
                     if(temp.retPieceNo()==9){
                        pawnBlackBase7.hide();
                        pawnBlackStalk7.hide();
                        pawnBlackHead7.hide();
                        blackBishop7.hide();
                        }
                     if(temp.retPieceNo()==10){
                        pawnBlackBase8.hide();
                        pawnBlackStalk8.hide();
                        pawnBlackHead8.hide();
                        blackBishop8.hide();
                        }
                     break;
            case 'H':if(temp.retPieceNo()==3){
                        pawnBlackBase1.hide();
                        pawnBlackStalk1.hide();
                        pawnBlackHead1.hide();
                        blackHorse1.hide();
                        }
                     if(temp.retPieceNo()==4){
                        pawnBlackBase2.hide();
                        pawnBlackStalk2.hide();
                        pawnBlackHead2.hide();
                        blackHorse2.hide();
                        }
                     if(temp.retPieceNo()==5){
                        pawnBlackBase3.hide();
                        pawnBlackStalk3.hide();
                        pawnBlackHead3.hide();
                        blackHorse3.hide();
                        }
                     if(temp.retPieceNo()==6){
                        pawnBlackBase4.hide();
                        pawnBlackStalk4.hide();
                        pawnBlackHead4.hide();
                        blackHorse4.hide();
                        }
                     if(temp.retPieceNo()==7){
                        pawnBlackBase5.hide();
                        pawnBlackStalk5.hide();
                        pawnBlackHead5.hide();
                        blackHorse5.hide();
                        }
                     if(temp.retPieceNo()==8){
                        pawnBlackBase6.hide();
                        pawnBlackStalk6.hide();
                        pawnBlackHead6.hide();
                        blackHorse6.hide();
                        }
                     if(temp.retPieceNo()==9){
                        pawnBlackBase7.hide();
                        pawnBlackStalk7.hide();
                        pawnBlackHead7.hide();
                        blackHorse7.hide();
                        }
                     if(temp.retPieceNo()==10){
                        pawnBlackBase8.hide();
                        pawnBlackStalk8.hide();
                        pawnBlackHead8.hide();
                        blackHorse8.hide();
                        }
                     break;
            case 'Q':if(temp.retPieceNo()==3){
                        pawnBlackBase1.hide();
                        pawnBlackStalk1.hide();
                        pawnBlackHead1.hide();
                        blackQueen1.hide();
                        }
                     if(temp.retPieceNo()==4){
                        pawnBlackBase2.hide();
                        pawnBlackStalk2.hide();
                        pawnBlackHead2.hide();
                        blackQueen2.hide();
                        }
                     if(temp.retPieceNo()==5){
                        pawnBlackBase3.hide();
                        pawnBlackStalk3.hide();
                        pawnBlackHead3.hide();
                        blackQueen3.hide();
                        }
                     if(temp.retPieceNo()==6){
                        pawnBlackBase4.hide();
                        pawnBlackStalk4.hide();
                        pawnBlackHead4.hide();
                        blackQueen4.hide();
                        }
                     if(temp.retPieceNo()==7){
                        pawnBlackBase5.hide();
                        pawnBlackStalk5.hide();
                        pawnBlackHead5.hide();
                        blackQueen5.hide();
                        }
                     if(temp.retPieceNo()==8){
                        pawnBlackBase6.hide();
                        pawnBlackStalk6.hide();
                        pawnBlackHead6.hide();
                        blackQueen6.hide();
                        }
                     if(temp.retPieceNo()==9){
                        pawnBlackBase7.hide();
                        pawnBlackStalk7.hide();
                        pawnBlackHead7.hide();
                        blackQueen7.hide();
                        }
                     if(temp.retPieceNo()==10){
                        pawnBlackBase8.hide();
                        pawnBlackStalk8.hide();
                        pawnBlackHead8.hide();
                        blackQueen8.hide();
                        }
                     break;
            }
        }
      }
    killMove=0;
    if(check(chessboard,currentColor)==1){
       if(checkMate(chessboard,currentColor)==1){
          Rectangle gameOver(683,384,240,80);
          gameOver.setColor(whiteCol);
          gameOver.setFill(true);
          if(currentColor=='w'){
             Text theEnd(683,384,"Black Wins the Game. White is CheckMate.");
             getClick();
          }else{
             Text theEnd(683,384,"White Wins the Game. Black is CheckMate.");
             getClick();
          }
       }
    }
    location=getClick();
    locationX=location/65536;
    locationY=location%65536;
    locationX=((locationX-363)/80);
    locationY=((locationY-64)/80);
    if(chessboard[locationX][locationY].retType()!='0' && chessboard[locationX][locationY].retColor()==currentColor){
       selected.moveTo(403+(locationX*80),104+(locationY*80));
       selected.show();
       to=getClick();
       toX=to/65536;
       toY=to%65536;
       toX=((toX-363)/80);
       toY=((toY-64)/80);
       selected.hide();
       temp.change('0','0',0);
       }
    else {continue;}
    switch(chessboard[locationX][locationY].retType()){
       case 'P': switch(chessboard[locationX][locationY].retColor()){
                    case 'w': killMove=0;
                              move=0;
                              if(toX-locationX==1 && (toY-locationY==1 || toY-locationY==-1) && chessboard[toX][toY].retColor()=='b'){
                                  killMove=1;
                                  move=1;
                                  temp=chessboard[toX][toY];
                                  }
                              if((toX-locationX==1 && toY-locationY==0 && chessboard[toX][toY].retColor()=='0')||
                                 (toX-locationX==2 && toY-locationY==0 && chessboard[toX][toY].retColor()=='0'
                                    && chessboard[toX-1][toY].retColor()=='0' && locationX==1)||killMove==1){
                                        if(chessboard[locationX][locationY].retPieceNo()==1){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','w',1);
                                             if(check(chessboard,'w')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','w',1);
                                                move=0;killMove=0;
                                             }else{
                                               movePawn(toX+1,char('a'+toY),pawnWhiteBase1,pawnWhiteStalk1,pawnWhiteHead1,'w');
                                               move=1;
                                               }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==2){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','w',2);
                                             if(check(chessboard,'w')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','w',2);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnWhiteBase2,pawnWhiteStalk2,pawnWhiteHead2,'w');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==3){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','w',3);
                                             if(check(chessboard,'w')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','w',3);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnWhiteBase3,pawnWhiteStalk3,pawnWhiteHead3,'w');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==4){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','w',4);
                                             if(check(chessboard,'w')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','w',4);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnWhiteBase4,pawnWhiteStalk4,pawnWhiteHead4,'w');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==5){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','w',5);
                                             if(check(chessboard,'w')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','w',5);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnWhiteBase5,pawnWhiteStalk5,pawnWhiteHead5,'w');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==6){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','w',6);
                                             if(check(chessboard,'w')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','w',6);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnWhiteBase6,pawnWhiteStalk6,pawnWhiteHead6,'w');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==7){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','w',7);
                                             if(check(chessboard,'w')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','w',7);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnWhiteBase7,pawnWhiteStalk7,pawnWhiteHead7,'w');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==8){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','w',8);
                                             if(check(chessboard,'w')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','w',8);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnWhiteBase8,pawnWhiteStalk8,pawnWhiteHead8,'w');
                                                move=1;
                                                }
                                             }
                              }
                              if(toX==7 && move==1){
                                 char promoted=promotion(currentColor);
                                 if(currentColor=='w'){
                                    if(chessboard[toX][toY].retPieceNo()==1 && promoted=='H'){
                                       whiteHorse1.moveTo(newX,newY);
                                       whiteHorse1.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==2 && promoted=='H'){
                                       whiteHorse2.moveTo(newX,newY);
                                       whiteHorse2.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==3 && promoted=='H'){
                                       whiteHorse3.moveTo(newX,newY);
                                       whiteHorse3.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==4 && promoted=='H'){
                                       whiteHorse4.moveTo(newX,newY);
                                       whiteHorse4.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==5 && promoted=='H'){
                                       whiteHorse5.moveTo(newX,newY);
                                       whiteHorse5.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==6 && promoted=='H'){
                                       whiteHorse6.moveTo(newX,newY);
                                       whiteHorse6.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==7 && promoted=='H'){
                                       whiteHorse7.moveTo(newX,newY);
                                       whiteHorse7.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==8 && promoted=='H'){
                                       whiteHorse8.moveTo(newX,newY);
                                       whiteHorse8.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==1 && promoted=='B'){
                                       whiteBishop1.moveTo(newX,newY);
                                       whiteBishop1.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==2 && promoted=='B'){
                                       whiteBishop2.moveTo(newX,newY);
                                       whiteBishop2.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==3 && promoted=='B'){
                                       whiteBishop3.moveTo(newX,newY);
                                       whiteBishop3.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==4 && promoted=='B'){
                                       whiteBishop4.moveTo(newX,newY);
                                       whiteBishop4.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==5 && promoted=='B'){
                                       whiteBishop5.moveTo(newX,newY);
                                       whiteBishop5.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==6 && promoted=='B'){
                                       whiteBishop6.moveTo(newX,newY);
                                       whiteBishop6.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==7 && promoted=='B'){
                                       whiteBishop7.moveTo(newX,newY);
                                       whiteBishop7.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==8 && promoted=='B'){
                                       whiteBishop8.moveTo(newX,newY);
                                       whiteBishop8.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==1 && promoted=='R'){
                                       whiteRook1.moveTo(newX,newY);
                                       whiteRook1.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==2 && promoted=='R'){
                                       whiteRook2.moveTo(newX,newY);
                                       whiteRook2.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==3 && promoted=='R'){
                                       whiteRook3.moveTo(newX,newY);
                                       whiteRook3.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==4 && promoted=='R'){
                                       whiteRook4.moveTo(newX,newY);
                                       whiteRook4.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==5 && promoted=='R'){
                                       whiteRook5.moveTo(newX,newY);
                                       whiteRook5.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==6 && promoted=='R'){
                                       whiteRook6.moveTo(newX,newY);
                                       whiteRook6.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==7 && promoted=='R'){
                                       whiteRook7.moveTo(newX,newY);
                                       whiteRook7.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==8 && promoted=='R'){
                                       whiteRook8.moveTo(newX,newY);
                                       whiteRook8.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==1 && promoted=='Q'){
                                       whiteQueen1.moveTo(newX,newY);
                                       whiteQueen1.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==2 && promoted=='Q'){
                                       whiteQueen2.moveTo(newX,newY);
                                       whiteQueen2.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==3 && promoted=='Q'){
                                       whiteQueen3.moveTo(newX,newY);
                                       whiteQueen3.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==4 && promoted=='Q'){
                                       whiteQueen4.moveTo(newX,newY);
                                       whiteQueen4.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==5 && promoted=='Q'){
                                       whiteQueen5.moveTo(newX,newY);
                                       whiteQueen5.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==6 && promoted=='Q'){
                                       whiteQueen6.moveTo(newX,newY);
                                       whiteQueen6.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==7 && promoted=='Q'){
                                       whiteQueen7.moveTo(newX,newY);
                                       whiteQueen7.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==8 && promoted=='Q'){
                                       whiteQueen8.moveTo(newX,newY);
                                       whiteQueen8.show();
                                    }
                                    chessboard[toX][toY].change(promoted,'w',chessboard[toX][toY].retPieceNo()+2);
                                 }
                              }
                              if(move==0)currentColor='w';
                              if(move==1){
                                currentColor='b';
                                move=0;
                              }
                              break;
                    case 'b': killMove=0;
                              move=0;
                              if(toX-locationX==-1 && (toY-locationY==1 || toY-locationY==-1) && chessboard[toX][toY].retColor()=='w'){
                                  killMove=1;
                                  temp=chessboard[toX][toY];
                                  }
                              if((toX-locationX==-1 && toY-locationY==0 && chessboard[toX][toY].retColor()=='0')||
                                 (toX-locationX==-2 && toY-locationY==0 && chessboard[toX][toY].retColor()=='0'
                                    && chessboard[toX+1][toY].retColor()=='0' && locationX==6)||killMove==1){
                                        if(chessboard[locationX][locationY].retPieceNo()==1){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','b',1);
                                             if(check(chessboard,'b')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','b',1);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnBlackBase1,pawnBlackStalk1,pawnBlackHead1,'b');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==2){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','b',2);
                                             if(check(chessboard,'b')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','b',2);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnBlackBase2,pawnBlackStalk2,pawnBlackHead2,'b');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==3){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','b',3);
                                             if(check(chessboard,'b')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','b',3);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnBlackBase3,pawnBlackStalk3,pawnBlackHead3,'b');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==4){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','b',4);
                                             if(check(chessboard,'b')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','b',4);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnBlackBase4,pawnBlackStalk4,pawnBlackHead4,'b');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==5){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','b',5);
                                             if(check(chessboard,'b')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','b',5);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnBlackBase5,pawnBlackStalk5,pawnBlackHead5,'b');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==6){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','b',6);
                                             if(check(chessboard,'b')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','b',6);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnBlackBase6,pawnBlackStalk6,pawnBlackHead6,'b');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==7){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','b',7);
                                             if(check(chessboard,'b')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','b',7);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnBlackBase7,pawnBlackStalk7,pawnBlackHead7,'b');
                                                move=1;
                                                }
                                             }
                                        if(chessboard[locationX][locationY].retPieceNo()==8){
                                             chessboard[locationX][locationY].change('0','0',0);
                                             chessboard[toX][toY].change('P','b',8);
                                             if(check(chessboard,'b')==1){
                                                chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                                chessboard[locationX][locationY].change('P','b',8);
                                                move=0;killMove=0;
                                             }else{
                                                movePawn(toX+1,char('a'+toY),pawnBlackBase8,pawnBlackStalk8,pawnBlackHead8,'b');
                                                move=1;
                                                }
                                             }
                              }
                              if(toX==0 && move==1){
                                 char promoted=promotion(currentColor);
                                 if(currentColor=='b'){
                                    if(chessboard[toX][toY].retPieceNo()==1 && promoted=='H'){
                                       blackHorse1.moveTo(newX,newY);
                                       blackHorse1.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==2 && promoted=='H'){
                                       blackHorse2.moveTo(newX,newY);
                                       blackHorse2.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==3 && promoted=='H'){
                                       blackHorse3.moveTo(newX,newY);
                                       blackHorse3.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==4 && promoted=='H'){
                                       blackHorse4.moveTo(newX,newY);
                                       blackHorse4.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==5 && promoted=='H'){
                                       blackHorse5.moveTo(newX,newY);
                                       blackHorse5.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==6 && promoted=='H'){
                                       blackHorse6.moveTo(newX,newY);
                                       blackHorse6.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==7 && promoted=='H'){
                                       blackHorse7.moveTo(newX,newY);
                                       blackHorse7.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==8 && promoted=='H'){
                                       blackHorse8.moveTo(newX,newY);
                                       blackHorse8.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==1 && promoted=='B'){
                                       blackBishop1.moveTo(newX,newY);
                                       blackBishop1.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==2 && promoted=='B'){
                                       blackBishop2.moveTo(newX,newY);
                                       blackBishop2.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==3 && promoted=='B'){
                                       blackBishop3.moveTo(newX,newY);
                                       blackBishop3.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==4 && promoted=='B'){
                                       blackBishop4.moveTo(newX,newY);
                                       blackBishop4.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==5 && promoted=='B'){
                                       blackBishop5.moveTo(newX,newY);
                                       blackBishop5.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==6 && promoted=='B'){
                                       blackBishop6.moveTo(newX,newY);
                                       blackBishop6.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==7 && promoted=='B'){
                                       blackBishop7.moveTo(newX,newY);
                                       blackBishop7.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==8 && promoted=='B'){
                                       blackBishop8.moveTo(newX,newY);
                                       blackBishop8.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==1 && promoted=='R'){
                                       blackRook1.moveTo(newX,newY);
                                       blackRook1.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==2 && promoted=='R'){
                                       blackRook2.moveTo(newX,newY);
                                       blackRook2.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==3 && promoted=='R'){
                                       blackRook3.moveTo(newX,newY);
                                       blackRook3.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==4 && promoted=='R'){
                                       blackRook4.moveTo(newX,newY);
                                       blackRook4.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==5 && promoted=='R'){
                                       blackRook5.moveTo(newX,newY);
                                       blackRook5.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==6 && promoted=='R'){
                                       blackRook6.moveTo(newX,newY);
                                       blackRook6.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==7 && promoted=='R'){
                                       blackRook7.moveTo(newX,newY);
                                       blackRook7.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==8 && promoted=='R'){
                                       blackRook8.moveTo(newX,newY);
                                       blackRook8.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==1 && promoted=='Q'){
                                       blackQueen1.moveTo(newX,newY);
                                       blackQueen1.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==2 && promoted=='Q'){
                                       blackQueen2.moveTo(newX,newY);
                                       blackQueen2.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==3 && promoted=='Q'){
                                       blackQueen3.moveTo(newX,newY);
                                       blackQueen3.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==4 && promoted=='Q'){
                                       blackQueen4.moveTo(newX,newY);
                                       blackQueen4.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==5 && promoted=='Q'){
                                       blackQueen5.moveTo(newX,newY);
                                       blackQueen5.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==6 && promoted=='Q'){
                                       blackQueen6.moveTo(newX,newY);
                                       blackQueen6.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==7 && promoted=='Q'){
                                       blackQueen7.moveTo(newX,newY);
                                       blackQueen7.show();
                                    }
                                    if(chessboard[toX][toY].retPieceNo()==8 && promoted=='Q'){
                                       blackQueen8.moveTo(newX,newY);
                                       blackQueen8.show();
                                    }
                                 chessboard[toX][toY].change(promoted,'b',chessboard[toX][toY].retPieceNo()+2);
                                 }
                              }
                              if(move==0)currentColor='b';
                              if(move==1){
                                currentColor='w';
                                move=0;
                              }
                              break;
                    }
                 break;
       case 'R': switch(chessboard[locationX][locationY].retColor()){
                      case 'w': killMove=0;
                                move=1;
                                if(toX==locationX){
                                   for(int i=0;i<mod(toY-locationY)-1;i++){
                                       if(chessboard[locationX][locationY+(((toY-locationY)/mod(toY-locationY))*(i+1))].retType()!='0'){
                                         move=0;
                                         }
                                       }
                                   }
                                else if(toY==locationY){
                                   for(int i=0;i<mod(toX-locationX)-1;i++){
                                       if(chessboard[locationX+(((toX-locationX)/mod(toX-locationX))*(i+1))][locationY].retType()!='0'){
                                         move=0;
                                         }
                                       }
                                   }
                                else{move=0;}
                                if(chessboard[toX][toY].retColor()=='w'){
                                   move=0;
                                }
                                if(chessboard[toX][toY].retColor()=='b' && move==1){
                                   killMove=1;
                                   temp=chessboard[toX][toY];
                                   }
                                if(move==1){
                                    chessboard[toX][toY].change('R','w',chessboard[locationX][locationY].retPieceNo());
                                    chessboard[locationX][locationY].change('0','0',0);
                                    if(check(chessboard,'w')==1){
                                       chessboard[locationX][locationY].change('R','w',chessboard[toX][toY].retPieceNo());
                                       chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                       move=0;killMove=0;
                                      }else
                                        {if(chessboard[toX][toY].retPieceNo()==1){
                                            moveRook(toX+1,char('a'+toY),rookWhiteBase1,rookF1White1,rookF2White1,rookF3White1,l1White1,l2White1,
                                                  'w');
                                            flagForCastlingWhite[0]=0;
                                            }
                                         if(chessboard[toX][toY].retPieceNo()==2){
                                            moveRook(toX+1,char('a'+toY),rookWhiteBase2,rookF1White2,rookF2White2,rookF3White2,l1White2,l2White2,
                                                  'w');
                                            flagForCastlingWhite[1]=0;
                                            }
                                         }
                                     }
                                   if(move==0)currentColor='w';
                                   if(move==1){
                                     currentColor='b';
                                     move=0;
                                     switch(chessboard[toX][toY].retPieceNo()){
                                        case 3:whiteRook1.moveTo(newX,newY);move=1;break;
                                        case 4:whiteRook2.moveTo(newX,newY);move=1;break;
                                        case 5:whiteRook3.moveTo(newX,newY);move=1;break;
                                        case 6:whiteRook4.moveTo(newX,newY);move=1;break;
                                        case 7:whiteRook5.moveTo(newX,newY);move=1;break;
                                        case 8:whiteRook6.moveTo(newX,newY);move=1;break;
                                        case 9:whiteRook7.moveTo(newX,newY);move=1;break;
                                        case 10:whiteRook8.moveTo(newX,newY);move=1;break;
                                     }
                                   }
                              break;
                     case 'b':  killMove=0;
                                move=1;
                                if(toX==locationX){
                                   for(int i=0;i<mod(toY-locationY)-1;i++){
                                       if(chessboard[locationX][locationY+(((toY-locationY)/mod(toY-locationY))*(i+1))].retType()!='0'){
                                         move=0;
                                         }
                                       }
                                   }
                                else if(toY==locationY){
                                   for(int i=0;i<mod(toX-locationX)-1;i++){
                                       if(chessboard[locationX+(((toX-locationX)/mod(toX-locationX))*(i+1))][locationY].retType()!='0'){
                                         move=0;
                                         }
                                       }
                                   }
                                else{move=0;}
                                if(chessboard[toX][toY].retColor()=='b'){
                                   move=0;
                                }
                                if(chessboard[toX][toY].retColor()=='w' && move==1){
                                   killMove=1;
                                   temp=chessboard[toX][toY];
                                   }
                                if(move==1){
                                   chessboard[toX][toY].change('R','b',chessboard[locationX][locationY].retPieceNo());
                                   chessboard[locationX][locationY].change('0','0',0);
                                   if(check(chessboard,'b')==1){
                                       chessboard[locationX][locationY].change('R','b',chessboard[toX][toY].retPieceNo());
                                       chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                       move=0;killMove=0;
                                      }else
                                        {if(chessboard[toX][toY].retPieceNo()==1){
                                            moveRook(toX+1,char('a'+toY),rookBlackBase1,rookF1Black1,rookF2Black1,rookF3Black1,l1Black1,l2Black1,
                                                  'b');
                                            flagForCastlingBlack[0]=0;
                                            }
                                         if(chessboard[toX][toY].retPieceNo()==2){
                                            moveRook(toX+1,char('a'+toY),rookBlackBase2,rookF1Black2,rookF2Black2,rookF3Black2,l1Black2,l2Black2,
                                                  'b');
                                            flagForCastlingBlack[1]=0;
                                            }
                                         }
                                   }
                                   if(move==0)currentColor='b';
                                   if(move==1){
                                     currentColor='w';
                                     move=0;
                                     switch(chessboard[toX][toY].retPieceNo()){
                                        case 3:blackRook1.moveTo(newX,newY);move=1;break;
                                        case 4:blackRook2.moveTo(newX,newY);move=1;break;
                                        case 5:blackRook3.moveTo(newX,newY);move=1;break;
                                        case 6:blackRook4.moveTo(newX,newY);move=1;break;
                                        case 7:blackRook5.moveTo(newX,newY);move=1;break;
                                        case 8:blackRook6.moveTo(newX,newY);move=1;break;
                                        case 9:blackRook7.moveTo(newX,newY);move=1;break;
                                        case 10:blackRook8.moveTo(newX,newY);move=1;break;
                                     }
                                   }
                              break;
                      }
                 break;
       case 'B': switch(chessboard[locationX][locationY].retColor()){
                     case 'w': killMove=0;
                               move=1;
                               if(mod(toX-locationX)!=mod(toY-locationY)){
                                  move=0;
                                  }
                               if(move==1){
                                  for(int i=0;i<mod(toX-locationX)-1;i++){
                                     if(chessboard[locationX+(((toX-locationX)/mod(toX-locationX))*(i+1))]
                                                  [locationY+(((toY-locationY)/mod(toY-locationY))*(i+1))].retType()!='0'){
                                                  move=0;
                                                  }
                                     }
                                  }
                               if(chessboard[toX][toY].retColor()=='w'){move=0;}
                               if(chessboard[toX][toY].retColor()=='b' && move==1){
                                  killMove=1;
                                  temp=chessboard[toX][toY];
                               }
                               if(move==1){
                                  chessboard[toX][toY].change('B','w',chessboard[locationX][locationY].retPieceNo());
                                  chessboard[locationX][locationY].change('0','0',0);
                                  if(check(chessboard,'w')==1){
                                      chessboard[locationX][locationY].change('B','w',chessboard[toX][toY].retPieceNo());
                                      chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                      move=0;killMove=0;
                                     }else{
                                       if(chessboard[toX][toY].retPieceNo()==1)
                                          moveBishop(toX+1,char('a'+toY),bishopC1White1,bishopC2White1,bishopC3White1,
                                                     bishopWhiteStalk1,bishopWhiteBase1,'w');
                                       if(chessboard[toX][toY].retPieceNo()==2)
                                          moveBishop(toX+1,char('a'+toY),bishopC1White2,bishopC2White2,bishopC3White2,
                                                     bishopWhiteStalk2,bishopWhiteBase2,'w');
                                       }
                                  }
                                  if(move==0)currentColor='w';
                                  if(move==1){
                                    currentColor='b';
                                    move=0;
                                    switch(chessboard[toX][toY].retPieceNo()){
                                        case 3:whiteBishop1.moveTo(newX,newY);move=1;break;
                                        case 4:whiteBishop2.moveTo(newX,newY);move=1;break;
                                        case 5:whiteBishop3.moveTo(newX,newY);move=1;break;
                                        case 6:whiteBishop4.moveTo(newX,newY);move=1;break;
                                        case 7:whiteBishop5.moveTo(newX,newY);move=1;break;
                                        case 8:whiteBishop6.moveTo(newX,newY);move=1;break;
                                        case 9:whiteBishop7.moveTo(newX,newY);move=1;break;
                                        case 10:whiteBishop8.moveTo(newX,newY);move=1;break;
                                     }
                                  }
                               break;
                     case 'b': killMove=0;
                               move=1;
                               if(mod(toX-locationX)!=mod(toY-locationY)){
                                  move=0;
                                  }
                               if(move==1){
                                  for(int i=0;i<mod(toX-locationX)-1;i++){
                                     if(chessboard[locationX+(((toX-locationX)/mod(toX-locationX))*(i+1))]
                                                  [locationY+(((toY-locationY)/mod(toY-locationY))*(i+1))].retType()!='0'){
                                                  move=0;
                                                  }
                                     }
                                  }
                               if(chessboard[toX][toY].retColor()=='b'){move=0;}
                               if(chessboard[toX][toY].retColor()=='w' && move==1){
                                  killMove=1;
                                  temp=chessboard[toX][toY];
                               }
                               if(move==1){
                                  chessboard[toX][toY].change('B','b',chessboard[locationX][locationY].retPieceNo());
                                  chessboard[locationX][locationY].change('0','0',0);
                                  if(check(chessboard,'b')==1){
                                      chessboard[locationX][locationY].change('B','b',chessboard[toX][toY].retPieceNo());
                                      chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                      move=0;killMove=0;
                                     }else{
                                        if(chessboard[toX][toY].retPieceNo()==1)
                                            moveBishop(toX+1,char('a'+toY),bishopC1Black1,bishopC2Black1,bishopC3Black1,
                                                       bishopBlackStalk1,bishopBlackBase1,'b');
                                        if(chessboard[toX][toY].retPieceNo()==2)
                                             moveBishop(toX+1,char('a'+toY),bishopC1Black2,bishopC2Black2,bishopC3Black2,
                                                        bishopBlackStalk2,bishopBlackBase2,'b');
                                      }
                                  }
                                  if(move==0)currentColor='b';
                                  if(move==1){
                                    currentColor='w';
                                    move=0;
                                    switch(chessboard[toX][toY].retPieceNo()){
                                        case 3:blackBishop1.moveTo(newX,newY);move=1;break;
                                        case 4:blackBishop2.moveTo(newX,newY);move=1;break;
                                        case 5:blackBishop3.moveTo(newX,newY);move=1;break;
                                        case 6:blackBishop4.moveTo(newX,newY);move=1;break;
                                        case 7:blackBishop5.moveTo(newX,newY);move=1;break;
                                        case 8:blackBishop6.moveTo(newX,newY);move=1;break;
                                        case 9:blackBishop7.moveTo(newX,newY);move=1;break;
                                        case 10:blackBishop8.moveTo(newX,newY);move=1;break;
                                     }
                                  }
                               break;
                     }
                     break;
       case 'H': switch(chessboard[locationX][locationY].retColor()){
                     case 'w': move=0;
                               killMove=0;
                               if(chessboard[toX][toY].retColor()!='w'){
                                  if(mod(toX-locationX)==2 && mod(toY-locationY)==1){move=1;}
                                  if(mod(toX-locationX)==1 && mod(toY-locationY)==2){move=1;}
                               }
                               if(move==1 && chessboard[toX][toY].retColor()=='b'){
                                  killMove=1;
                                  temp=chessboard[toX][toY];
                               }
                               if(move==1){
                                  chessboard[toX][toY].change('H','w',chessboard[locationX][locationY].retPieceNo());
                                  chessboard[locationX][locationY].change('0','0',0);
                                  if(check(chessboard,'w')==1){
                                      chessboard[locationX][locationY].change('H','w',chessboard[toX][toY].retPieceNo());
                                      chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                      move=0;killMove=0;
                                     }else{
                                        if(chessboard[toX][toY].retPieceNo()==1)
                                           moveHorse(toX+1,char('a'+toY),horseWhiteStalk1,horseWhiteHair1,horseFace1White1,
                                                     horseFace2White1,horseWhiteBase1,'w');
                                        if(chessboard[toX][toY].retPieceNo()==2)
                                           moveHorse(toX+1,char('a'+toY),horseWhiteStalk2,horseWhiteHair2,horseFace1White2,
                                                     horseFace2White2,horseWhiteBase2,'w');
                                     }
                               }
                               if(move==0)currentColor='w';
                               if(move==1){
                                 currentColor='b';
                                 move=0;
                                 switch(chessboard[toX][toY].retPieceNo()){
                                        case 3:whiteHorse1.moveTo(newX,newY);move=1;break;
                                        case 4:whiteHorse2.moveTo(newX,newY);move=1;break;
                                        case 5:whiteHorse3.moveTo(newX,newY);move=1;break;
                                        case 6:whiteHorse4.moveTo(newX,newY);move=1;break;
                                        case 7:whiteHorse5.moveTo(newX,newY);move=1;break;
                                        case 8:whiteHorse6.moveTo(newX,newY);move=1;break;
                                        case 9:whiteHorse7.moveTo(newX,newY);move=1;break;
                                        case 10:whiteHorse8.moveTo(newX,newY);move=1;break;
                                     }
                                 }
                               break;
                     case 'b': move=0;
                               killMove=0;
                               if(chessboard[toX][toY].retColor()!='b'){
                                  if(mod(toX-locationX)==2 && mod(toY-locationY)==1){move=1;}
                                  if(mod(toX-locationX)==1 && mod(toY-locationY)==2){move=1;}
                               }
                               if(move==1 && chessboard[toX][toY].retColor()=='w'){
                                  killMove=1;
                                  temp=chessboard[toX][toY];
                               }
                               if(move==1){
                                  chessboard[toX][toY].change('H','b',chessboard[locationX][locationY].retPieceNo());
                                  chessboard[locationX][locationY].change('0','0',0);
                                  if(check(chessboard,'b')==1){
                                      chessboard[locationX][locationY].change('H','b',chessboard[toX][toY].retPieceNo());
                                      chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                      move=0;killMove=0;
                                     }else{
                                       if(chessboard[toX][toY].retPieceNo()==1)
                                           moveHorse(toX+1,char('a'+toY),horseBlackStalk1,horseBlackHair1,horseFace1Black1,
                                                     horseFace2Black1,horseBlackBase1,'b');
                                       if(chessboard[toX][toY].retPieceNo()==2)
                                           moveHorse(toX+1,char('a'+toY),horseBlackStalk2,horseBlackHair2,horseFace1Black2,
                                                     horseFace2Black2,horseBlackBase2,'b');
                                     }
                                  }
                               if(move==0)currentColor='b';
                               if(move==1){
                                 currentColor='w';
                                 move=0;
                                 switch(chessboard[toX][toY].retPieceNo()){
                                        case 3:blackHorse1.moveTo(newX,newY);move=1;break;
                                        case 4:blackHorse2.moveTo(newX,newY);move=1;break;
                                        case 5:blackHorse3.moveTo(newX,newY);move=1;break;
                                        case 6:blackHorse4.moveTo(newX,newY);move=1;break;
                                        case 7:blackHorse5.moveTo(newX,newY);move=1;break;
                                        case 8:blackHorse6.moveTo(newX,newY);move=1;break;
                                        case 9:blackHorse7.moveTo(newX,newY);move=1;break;
                                        case 10:blackHorse8.moveTo(newX,newY);move=1;break;
                                     }
                                 }
                               break;
                     }
                 break;
       case 'Q': switch(chessboard[locationX][locationY].retColor()){
                     case 'w': move=1;
                               killMove=0;
                               if((mod(toX-locationX)!=mod(toY-locationY)) && (toX!=locationX) && (toY!=locationY)){move=0;}
                               if(chessboard[toX][toY].retColor()=='w'){move=0;}
                               if(move==1){
                                  if(toX==locationX){
                                     for(int i=0;i<mod(toY-locationY)-1;i++){
                                         if(chessboard[locationX][locationY+(((toY-locationY)/mod(toY-locationY))*(i+1))].retType()!='0'){
                                           move=0;
                                           }
                                         }
                                     }
                                  else if(toY==locationY){
                                     for(int i=0;i<mod(toX-locationX)-1;i++){
                                         if(chessboard[locationX+(((toX-locationX)/mod(toX-locationX))*(i+1))][locationY].retType()!='0'){
                                           move=0;
                                           }
                                         }
                                   }
                                  else{
                                     for(int i=0;i<mod(toX-locationX)-1;i++){
                                        if(chessboard[locationX+(((toX-locationX)/mod(toX-locationX))*(i+1))]
                                                     [locationY+(((toY-locationY)/mod(toY-locationY))*(i+1))].retType()!='0'){
                                                     move=0;
                                                     }
                                        }
                                     }
                                  }
                               if(move==1 && chessboard[toX][toY].retColor()=='b'){
                                  killMove=1;
                                  temp=chessboard[toX][toY];
                               }
                               if(move==1){
                                  chessboard[toX][toY].change('Q','w',chessboard[locationX][locationY].retPieceNo());
                                  chessboard[locationX][locationY].change('0','0',0);
                                  if(check(chessboard,'w')==1){
                                        chessboard[locationX][locationY].change('Q','w',chessboard[locationX][locationY].retPieceNo());
                                        chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                        move=0;killMove=0;
                                     }else
                                      if(chessboard[toX][toY].retPieceNo()==1)
                                        moveQueen(toX+1,char('a'+toY),queenWhiteBase,queenL1White,queenL2White,queenL3White,queenL4White,
                                                  queenL5White,queenL6White,queenL7White,queenL8White,queenL9White,queenC1White,
                                                  queenC2White,queenC3White,'w');
                                  }
                               if(move==0)currentColor='w';
                               if(move==1){
                                 currentColor='b';
                                 move=0;
                                 switch(chessboard[toX][toY].retPieceNo()){
                                        case 3:whiteQueen1.moveTo(newX,newY);move=1;break;
                                        case 4:whiteQueen2.moveTo(newX,newY);move=1;break;
                                        case 5:whiteQueen3.moveTo(newX,newY);move=1;break;
                                        case 6:whiteQueen4.moveTo(newX,newY);move=1;break;
                                        case 7:whiteQueen5.moveTo(newX,newY);move=1;break;
                                        case 8:whiteQueen6.moveTo(newX,newY);move=1;break;
                                        case 9:whiteQueen7.moveTo(newX,newY);move=1;break;
                                        case 10:whiteQueen8.moveTo(newX,newY);move=1;break;
                                     }
                               }
                               break;
                     case 'b': move=1;
                               killMove=0;
                               if((mod(toX-locationX)!=mod(toY-locationY)) && (toX!=locationX) && (toY!=locationY)){move=0;}
                               if(chessboard[toX][toY].retColor()=='b'){move=0;}
                               if(move==1){
                                  if(toX==locationX){
                                     for(int i=0;i<mod(toY-locationY)-1;i++){
                                         if(chessboard[locationX][locationY+(((toY-locationY)/mod(toY-locationY))*(i+1))].retType()!='0'){
                                           move=0;
                                           }
                                         }
                                     }
                                  else if(toY==locationY){
                                     for(int i=0;i<mod(toX-locationX)-1;i++){
                                         if(chessboard[locationX+(((toX-locationX)/mod(toX-locationX))*(i+1))][locationY].retType()!='0'){
                                           move=0;
                                           }
                                         }
                                   }
                                  else{
                                     for(int i=0;i<mod(toX-locationX)-1;i++){
                                        if(chessboard[locationX+(((toX-locationX)/mod(toX-locationX))*(i+1))]
                                                     [locationY+(((toY-locationY)/mod(toY-locationY))*(i+1))].retType()!='0'){
                                                     move=0;
                                                     }
                                        }
                                     }
                                  }
                               if(move==1 && chessboard[toX][toY].retColor()=='w'){
                                  killMove=1;
                                  temp=chessboard[toX][toY];
                               }
                               if(move==1){
                                  chessboard[toX][toY].change('Q','b',chessboard[locationX][locationY].retPieceNo());
                                  chessboard[locationX][locationY].change('0','0',0);
                                  if(check(chessboard,'b')==1){
                                        chessboard[locationX][locationY].change('Q','b',chessboard[toX][toY].retPieceNo());
                                        chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                        move=0;killMove=0;
                                     }else
                                        if(chessboard[toX][toY].retPieceNo()==1)
                                           moveQueen(toX+1,char('a'+toY),queenBlackBase,queenL1Black,queenL2Black,queenL3Black,queenL4Black,
                                                  queenL5Black,queenL6Black,queenL7Black,queenL8Black,queenL9Black,queenC1Black,
                                                  queenC2Black,queenC3Black,'b');
                                  }
                               if(move==0)currentColor='b';
                               if(move==1){
                                 currentColor='w';
                                 move=0;
                                 switch(chessboard[toX][toY].retPieceNo()){
                                        case 3:blackQueen1.moveTo(newX,newY);move=1;break;
                                        case 4:blackQueen2.moveTo(newX,newY);move=1;break;
                                        case 5:blackQueen3.moveTo(newX,newY);move=1;break;
                                        case 6:blackQueen4.moveTo(newX,newY);move=1;break;
                                        case 7:blackQueen5.moveTo(newX,newY);move=1;break;
                                        case 8:blackQueen6.moveTo(newX,newY);move=1;break;
                                        case 9:blackQueen7.moveTo(newX,newY);move=1;break;
                                        case 10:blackQueen8.moveTo(newX,newY);move=1;break;
                                     }
                               }
                               break;
                     }
                 break;
       case 'K': switch(chessboard[locationX][locationY].retColor()){
                     case 'w': move=0;
                               killMove=0;
                               if((mod(toX-locationX)<=1 && mod(toY-locationY)<=1) && (toX-locationX!=0 || toY-locationY!=0)){move=1;}
                               if(toX==locationX && toY==locationY){move=0;}
                               if(chessboard[toX][toY].retColor()=='w' && move==1){move=0;}
                               if(chessboard[toX][toY].retColor()=='b' && move==1){
                                  killMove=1;
                                  temp=chessboard[toX][toY];
                               }
                               if(move==1){
                                  chessboard[locationX][locationY].change('0','0',0);
                                  chessboard[toX][toY].change('K','w',1);
                                  if(check(chessboard,'w')==1){
                                    chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                    chessboard[locationX][locationY].change('K','w',1);
                                    move=0;killMove=0;
                                  }else
                                   {moveKing(toX+1,char('a'+toY),kingC1White,kingC2White,kingL1White,kingL2White,kingL3White,kingL4White,
                                              kingBase1White,kingBase2White,kingWhiteHead,kingL5White,kingL6White,'w');
                                    flagForCastlingWhite[0]=0;flagForCastlingWhite[1]=0;
                                    }
                               }
                               if(check(chessboard,'w')==0)
                               if(toY-locationY==2 && flagForCastlingWhite[1]==1 && toX==0 && locationX==0){
                                  if(chessboard[0][5].retType()=='0' && chessboard[0][6].retType()=='0'){
                                     chessboard[0][5].change('K','w',1);
                                     chessboard[0][4].change('0','0',0);
                                     if(check(chessboard,'w')==0){
                                        chessboard[0][6].change('K','w',1);
                                        chessboard[0][5].change('R','w',2);
                                        chessboard[0][7].change('0','0',0);
                                        if(check(chessboard,'w')==0){
                                           moveKing(toX+1,char('a'+toY),kingC1White,kingC2White,kingL1White,kingL2White,kingL3White,kingL4White,
                                                    kingBase1White,kingBase2White,kingWhiteHead,kingL5White,kingL6White,'w');
                                           moveRook(toX+1,char('a'+toY-1),rookWhiteBase2,rookF1White2,rookF2White2,rookF3White2,l1White2,l2White2,
                                                    'w');
                                           flagForCastlingWhite[0]=0;flagForCastlingWhite[1]=0;
                                           move=1;
                                        }
                                        else{
                                           chessboard[0][7].change('R','w',2);
                                           chessboard[0][4].change('K','w',1);
                                           chessboard[0][5].change('0','0',0);
                                           chessboard[0][6].change('0','0',0);
                                        }
                                     }
                                     else{
                                        chessboard[0][4].change('K','w',1);
                                        chessboard[0][5].change('0','0',0);
                                     }
                                  }
                               }
                               if(check(chessboard,'w')==0)
                               if(toY-locationY==-2 && flagForCastlingWhite[0]==1 && toX==0 && locationX==0){
                                  if(chessboard[0][3].retType()=='0' && chessboard[0][2].retType()=='0'){
                                     chessboard[0][3].change('K','w',1);
                                     chessboard[0][4].change('0','0',0);
                                     if(check(chessboard,'w')==0){
                                        chessboard[0][2].change('K','w',1);
                                        chessboard[0][3].change('R','w',1);
                                        chessboard[0][0].change('0','0',0);
                                        if(check(chessboard,'w')==0){
                                           moveKing(toX+1,char('a'+toY),kingC1White,kingC2White,kingL1White,kingL2White,kingL3White,kingL4White,
                                                    kingBase1White,kingBase2White,kingWhiteHead,kingL5White,kingL6White,'w');
                                           moveRook(toX+1,char('a'+toY+1),rookWhiteBase1,rookF1White1,rookF2White1,rookF3White1,l1White1,l2White1,
                                                    'w');
                                           flagForCastlingWhite[0]=0;flagForCastlingWhite[1]=0;
                                           move=1;
                                        }
                                        else{
                                           chessboard[0][0].change('R','w',1);
                                           chessboard[0][4].change('K','w',1);
                                           chessboard[0][3].change('0','0',0);
                                           chessboard[0][2].change('0','0',0);
                                        }
                                     }
                                     else{
                                        chessboard[0][4].change('K','w',1);
                                        chessboard[0][3].change('0','0',0);
                                     }
                                  }
                               }
                               if(move==0)currentColor='w';
                               if(move==1){
                                 currentColor='b';
                                 move=0;
                               }
                               break;
                     case 'b': move=0;
                               killMove=0;
                               if(mod(toX-locationX)<=1 && mod(toY-locationY)<=1 && (toX-locationX!=0 || toY-locationY!=0)){move=1;}
                               if(toX==locationX && toY==locationY){move=0;}
                               if(chessboard[toX][toY].retColor()=='b' && move==1){move=0;}
                               if(chessboard[toX][toY].retColor()=='w' && move==1){
                                  killMove=1;
                                  temp=chessboard[toX][toY];
                               }
                               if(move==1){
                                  chessboard[locationX][locationY].change('0','0',0);
                                  chessboard[toX][toY].change('K','b',1);
                                  if(check(chessboard,'b')==1){
                                    chessboard[toX][toY].change(temp.retType(),temp.retColor(),temp.retPieceNo());
                                    chessboard[locationX][locationY].change('K','b',1);
                                    move=0;killMove=0;
                                  }else
                                    {moveKing(toX+1,char('a'+toY),kingC1Black,kingC2Black,kingL1Black,kingL2Black,kingL3Black,kingL4Black,
                                              kingBase1Black,kingBase2Black,kingBlackHead,kingL5Black,kingL6Black,'b');
                                     flagForCastlingBlack[0]=0;flagForCastlingBlack[1]=0;
                                     }
                               }
                               if(check(chessboard,'b')==0)
                               if(toY-locationY==2 && flagForCastlingBlack[1]==1 && toX==7 && locationX==7){
                                  if(chessboard[7][5].retType()=='0' && chessboard[7][6].retType()=='0'){
                                     chessboard[7][5].change('K','b',1);
                                     chessboard[7][4].change('0','0',0);
                                     if(check(chessboard,'b')==0){
                                        chessboard[7][6].change('K','b',1);
                                        chessboard[7][5].change('R','b',2);
                                        chessboard[7][7].change('0','0',0);
                                        if(check(chessboard,'b')==0){
                                           moveKing(toX+1,char('a'+toY),kingC1Black,kingC2Black,kingL1Black,kingL2Black,kingL3Black,kingL4Black,
                                                    kingBase1Black,kingBase2Black,kingBlackHead,kingL5Black,kingL6Black,'b');
                                           moveRook(toX+1,char('a'+toY-1),rookBlackBase2,rookF1Black2,rookF2Black2,rookF3Black2,l1Black2,l2Black2,
                                                    'b');
                                           flagForCastlingBlack[0]=0;flagForCastlingBlack[1]=0;
                                           move=1;
                                        }
                                        else{
                                           chessboard[7][7].change('R','b',2);
                                           chessboard[7][4].change('K','b',1);
                                           chessboard[7][5].change('0','0',0);
                                           chessboard[7][6].change('0','0',0);
                                        }
                                     }
                                     else{
                                        chessboard[7][4].change('K','b',1);
                                        chessboard[7][5].change('0','0',0);
                                     }
                                  }
                               }
                               if(check(chessboard,'b')==0)
                               if(toY-locationY==-2 && flagForCastlingBlack[0]==1 && toX==7 && locationX==7){
                                  if(chessboard[7][3].retType()=='0' && chessboard[7][2].retType()=='0'){
                                     chessboard[7][3].change('K','b',1);
                                     chessboard[7][4].change('0','0',0);
                                     if(check(chessboard,'b')==0){
                                        chessboard[7][2].change('K','b',1);
                                        chessboard[7][3].change('R','b',1);
                                        chessboard[7][0].change('0','0',0);
                                        if(check(chessboard,'b')==0){
                                           moveKing(toX+1,char('a'+toY),kingC1Black,kingC2Black,kingL1Black,kingL2Black,kingL3Black,kingL4Black,
                                                    kingBase1Black,kingBase2Black,kingBlackHead,kingL5Black,kingL6Black,'b');
                                           moveRook(toX+1,char('a'+toY+1),rookBlackBase1,rookF1Black1,rookF2Black1,rookF3Black1,l1Black1,l2Black1,
                                                    'b');
                                           flagForCastlingBlack[0]=0;flagForCastlingBlack[1]=0;
                                           move=1;
                                        }
                                        else{
                                           chessboard[7][0].change('R','b',1);
                                           chessboard[7][4].change('K','b',1);
                                           chessboard[7][3].change('0','0',0);
                                           chessboard[7][2].change('0','0',0);
                                        }
                                     }
                                     else{
                                        chessboard[7][4].change('K','b',1);
                                        chessboard[7][3].change('0','0',0);
                                     }
                                  }
                               }
                               if(move==0)currentColor='b';
                               if(move==1){
                                currentColor='w';
                                move=0;
                               }
                               break;
                     }
                     break;
       }
      if(currentColor=='b' && move==1){
        if(chessboard[toX][toY].retPieceNo()==3){
           movePawn(toX+1,char('a'+toY),pawnWhiteBase1,pawnWhiteStalk1,pawnWhiteHead1,'w');
        }
        if(chessboard[toX][toY].retPieceNo()==4){
           movePawn(toX+1,char('a'+toY),pawnWhiteBase2,pawnWhiteStalk2,pawnWhiteHead2,'w');
        }
        if(chessboard[toX][toY].retPieceNo()==5){
           movePawn(toX+1,char('a'+toY),pawnWhiteBase3,pawnWhiteStalk3,pawnWhiteHead3,'w');
        }
        if(chessboard[toX][toY].retPieceNo()==6){
           movePawn(toX+1,char('a'+toY),pawnWhiteBase4,pawnWhiteStalk4,pawnWhiteHead4,'w');
        }
        if(chessboard[toX][toY].retPieceNo()==7){
           movePawn(toX+1,char('a'+toY),pawnWhiteBase5,pawnWhiteStalk5,pawnWhiteHead5,'w');
        }
        if(chessboard[toX][toY].retPieceNo()==8){
           movePawn(toX+1,char('a'+toY),pawnWhiteBase6,pawnWhiteStalk6,pawnWhiteHead6,'w');
        }
        if(chessboard[toX][toY].retPieceNo()==9){
           movePawn(toX+1,char('a'+toY),pawnWhiteBase7,pawnWhiteStalk7,pawnWhiteHead7,'w');
        }
        if(chessboard[toX][toY].retPieceNo()==10){
           movePawn(toX+1,char('a'+toY),pawnWhiteBase8,pawnWhiteStalk8,pawnWhiteHead8,'w');
        }
        move=0;
      }
      if(currentColor=='w' && move==1){
        if(chessboard[toX][toY].retPieceNo()==3){
           movePawn(toX+1,char('a'+toY),pawnBlackBase1,pawnBlackStalk1,pawnBlackHead1,'b');
        }
        if(chessboard[toX][toY].retPieceNo()==4){
            movePawn(toX+1,char('a'+toY),pawnBlackBase2,pawnBlackStalk2,pawnBlackHead2,'b');
        }
        if(chessboard[toX][toY].retPieceNo()==5){
           movePawn(toX+1,char('a'+toY),pawnBlackBase3,pawnBlackStalk3,pawnBlackHead3,'b');
        }
        if(chessboard[toX][toY].retPieceNo()==6){
           movePawn(toX+1,char('a'+toY),pawnBlackBase4,pawnBlackStalk4,pawnBlackHead4,'b');
        }
        if(chessboard[toX][toY].retPieceNo()==7){
           movePawn(toX+1,char('a'+toY),pawnBlackBase5,pawnBlackStalk5,pawnBlackHead5,'b');
        }
        if(chessboard[toX][toY].retPieceNo()==8){
           movePawn(toX+1,char('a'+toY),pawnBlackBase6,pawnBlackStalk6,pawnBlackHead6,'b');
        }
        if(chessboard[toX][toY].retPieceNo()==9){
           movePawn(toX+1,char('a'+toY),pawnBlackBase7,pawnBlackStalk7,pawnBlackHead7,'b');
        }
        if(chessboard[toX][toY].retPieceNo()==10){
            movePawn(toX+1,char('a'+toY),pawnBlackBase8,pawnBlackStalk8,pawnBlackHead8,'b');
        }
        move=0;
      }
    }while(1);
  }
  else if((locationX<=300 && locationX>=0) && (locationY<=768 && locationY>=468)){
        break;
        }
 }while(1);
}
