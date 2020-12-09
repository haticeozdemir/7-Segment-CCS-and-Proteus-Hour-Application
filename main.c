#include <main.h>


int milisaniye = 0;
int saniye = 0;
int dakika = 0;
int saat = 0;
int saniye1,saniye2;
int dakika1,dakika2;
int saat1,saat2;
// ÜSTEKİLER NORMAL SAATİN
//ALTTAKİLER ALARM SAATİNİN 
int alarmmilisaniye = 0;
int alarmsaniye = 0;
int alarmdakika = 0;
int alarmsaat =0;
int asaniye1,asaniye2;
int adakika1,adakika2;
int asaat1,asaat2;

int azaltmak,arttirmak,secmek,ayar;// AYAR YAPMAK İÇİN

#int_timer1
void timer1(){

   milisaniye++;
   output_a(milisaniye);
   
   if(milisaniye == 10){
   milisaniye=0;
   saniye++;
   
      if(saniye == 60){
      saniye=0;
      dakika++;
      
         if(dakika == 60){
         dakika = 0;
         saat++;
         
            if(saat==24){
            saat=0;
              
            }
         }
      }

      saniye1 = saniye%10;
      saniye2 = (saniye/10)%10;
      output_d(saniye1 | saniye2 <<4 );
      
      dakika1 = dakika%10;
      dakika2 = (dakika/10)%10;
      output_c(dakika1 | dakika2 <<4);
      
      saat1 = saat%10;
      saat2 = (saat/10)%10;
      output_b(saat1 | saat2 <<4);
      
   }
}

void SaatGoster(){
  
   output_a(milisaniye);
   output_d(saniye1 | saniye2 <<4 );
   output_c(dakika1 | dakika2 <<4);
   output_b(saat1 | saat2 <<4);

}

void AlarmGoster(){
   int secim=0;
  // disable_interrupts(int_timer1);

   while(ayar == 0){
   ayar = input(pin_e0);// SAATİ TEKRAR BAŞLATANA KADAR
   secmek = input(pin_e1); // KUR PİNİ İLE SEÇİM 
   arttirmak = input(pin_a4); // ARTTIRMAK İÇİN
   azaltmak = input(pin_a5);  //AZALTMAK İçin
   
   if(secmek == 1)
   {
   secim++;
   delay_ms(250);
   }
   
    if(secim ==0){
      if(arttirmak == 1){
      alarmmilisaniye++;
      delay_ms(250);
         if(alarmmilisaniye >=10){alarmmilisaniye = 0;}
      }
      if(azaltmak ==1){
      alarmmilisaniye--;
      delay_ms(250);
         if(alarmmilisaniye <=0){alarmmilisaniye = 9;}
      }
    }
 
        if(secim ==1){
      if(arttirmak == 1){
      alarmsaniye++;
     delay_ms(250);
         if(alarmsaniye >=60){alarmsaniye = 0;}
      }
      if(azaltmak ==1){
      alarmsaniye--;
      delay_ms(250);
         if(alarmsaniye <=0){alarmsaniye = 59;}
      }
    }
    
     if(secim ==2){
      if(arttirmak == 1){
      alarmdakika++;
      delay_ms(250);
         if(alarmdakika >=60){alarmdakika = 0;}
      }
      if(azaltmak ==1){
      alarmdakika--;
      delay_ms(250);
         if(alarmdakika <=0){alarmdakika = 59;}
      }
    }

    if(secim ==3){
      if(arttirmak == 1){
      alarmsaat++;
      delay_ms(250);
         if(alarmsaat >=24){alarmsaat = 0;}
      }
      if(azaltmak ==1){
      alarmsaat--;
      delay_ms(250);
         if(alarmsaat <=0){alarmsaat = 23;}
      }
    }

    if(secim > 3){
    secim = 0;
    delay_ms(250);
    }
      
      output_a(alarmmilisaniye);
      asaniye1 = alarmsaniye%10;
      asaniye2 = (alarmsaniye/10)%10;
      output_d(asaniye1 | asaniye2 <<4 );
      
      adakika1 = alarmdakika%10;
      adakika2 = (alarmdakika/10)%10;
      output_c(adakika1 | adakika2 <<4);
      
      asaat1 = alarmsaat%10;
      asaat2 = (alarmsaat/10)%10;
      output_b(asaat1 | asaat2 <<4);

   }//while

}
  


   


void AlarmKontrol(){

 
}

void main()
{
   int saatalarm=0;
 
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
   enable_interrupts(int_timer1);
   enable_interrupts(global);
   

   while(TRUE)
   {
      saatalarm = input(pin_e0);
  
      while(saatalarm==1){
         enable_interrupts(int_timer1);
         SaatGoster();
         if(alarmmilisaniye == milisaniye && alarmsaniye == saniye && alarmdakika == dakika && alarmsaat == saat){
         
              output_high(pin_e2); 
   }
         
      }
         disable_interrupts(int_timer1);
         AlarmGoster();
   }}
