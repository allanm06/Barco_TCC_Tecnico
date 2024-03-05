#define mf porta.ra0
#define mr porta.ra1
#define le porta.ra2
#define ld porta.ra3
#define f portb.rb0
#define r portb.rb1
#define d portb.rb2
#define e portb.rb3
#define ac portb.rb4
#define dc portb.rb5

char k=10,x1=0,x2=0;

void main()
{
trisa=15;
trisb=48;
portb=0;
while(1)
 {
  if((mf==0)&&(mr==0)){f=0;r=0;}
  if((mf==1)&&(mr==1)){r=0;f=0;}
  if((mf==1)&&(mr==0)){f=1;vdelay_ms(20-k);} //Acionamento para frente com PWM
  if((mf==1)&&(mr==0)){f=0;vdelay_ms(k);}
  if((mr==1)&&(mf==0)){r=1;vdelay_ms(20-k);} //Acionamento para trás com PWM
  if((mr==1)&&(mf==0)){r=0;vdelay_ms(k);}
  
  if((ld==0)&&(le==0)){d=0;e=0;}
  if((ld==1)&&(le==1)){d=0;e=0;}
  if((ld==1)&&(le==0)){d=1;} //Acionamento do Leme para a Direita
  if((le==1)&&(ld==0)){e=1;} //Acionamento do leme Para Esquerda
  
  if((ac==1)&&(x1==0)){k++;x1=1;} //Aumento do PWM(Motor desacelera)
  if((ac==0)&&(x1==1))x1=0;
  if((dc==1)&&(x2==0)){k--;x2=1;} //Diminuição do PWM(Motor Acelera)
  if((dc==0)&&(x2==1))x2=0;
  
  if(k==0)k=1;
  if(k==50)k=19;
  
 }
}