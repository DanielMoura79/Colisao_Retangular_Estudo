#include <allegro.h>

int main()
{
  //INICIALIZACAO
  allegro_init();
  install_timer();
  install_keyboard();
  install_mouse();
  set_color_depth(32);
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
  set_window_title("Colision Boxes");
  
  //VARIAVEIS
  BITMAP *buffer = create_bitmap(800,600);
  int Ax1=300; int Ay1=200; int Ax2=500; int Ay2=400;
  int Bx1=  0; int By1=  0; int Bx2=  0; int By2=  0;
  int colisao=0;
  int temp1x=0;  int temp1y=0;  int temp2x=0;  int temp2y=0;
  
  while(!key[KEY_ESC])
  {
    //LOOP DE JOGO
    //desenha caixas
    if (mouse_b & 1) { Bx1=mouse_x; By1=mouse_y; };
    if (mouse_b & 2) { Bx2=mouse_x; By2=mouse_y; };
    //desenha primitivas
    circle (buffer, mouse_x, mouse_y, 2, makecol(255,255,000));
    rect (buffer, Bx1, By1, Bx2, By2, makecol(255,000,000));
		rect (buffer, Ax1, Ay1, Ax2, Ay2, makecol(000,000,255));
		//textos
		textprintf_ex(buffer, font, 20, 20, makecol(255, 255, 255), -1, "USE OS BOTOES ESQUERDO E DIREITO DO MOUSE PARA DESENHAR OS HITBOXES");
		if ( colisao==0 ) { textprintf_ex(buffer, font, 20, 30, makecol(255, 255, 255), -1, "NAO COLIDIU."); };
		if ( colisao==1 ) { textprintf_ex(buffer, font, 20, 30, makecol(255, 255, 000), -1, "COLIDIU!"); };
		textprintf_centre_ex(buffer, font, Ax1, Ay1-10, makecol(255, 255, 255), -1, "%i,%i", Ax1, Ay1);
		textprintf_centre_ex(buffer, font, Ax2, Ay2+05, makecol(255, 255, 255), -1, "%i,%i", Ax2, Ay2);
		textprintf_centre_ex(buffer, font, Bx1, By1-10, makecol(255, 255, 255), -1, "%i,%i", Bx1, By1);
		textprintf_centre_ex(buffer, font, Bx2, By2+05, makecol(255, 255, 255), -1, "%i,%i", Bx2, By2);
		//Correcao do box
    temp1x=0;  temp1y=0;  temp2x=0;  temp2y=0; 
		temp1x=Ax1; temp1y=Ay1; temp2x=Ax2; temp2y=Ay2;
    if (temp1x<=temp2x) { Ax1=temp1x; };
    if (temp1x >temp2x) { Ax1=temp2x; };
    if (temp1y<=temp2y) { Ay1=temp1y; };
    if (temp1y >temp2y) { Ay1=temp2y; };
    if (temp2x >temp1x) { Ax2=temp2x; };
    if (temp2x<=temp1x) { Ax2=temp1x; };
    if (temp2y >temp1y) { Ay2=temp2y; };
    if (temp2y<=temp1y) { Ay2=temp1y; };
    temp1x=0;  temp1y=0;  temp2x=0;  temp2y=0; 
		temp1x=Bx1; temp1y=By1; temp2x=Bx2; temp2y=By2;
    if (temp1x<=temp2x) { Bx1=temp1x; };
    if (temp1x >temp2x) { Bx1=temp2x; };
    if (temp1y<=temp2y) { By1=temp1y; };
    if (temp1y >temp2y) { By1=temp2y; };
    if (temp2x >temp1x) { Bx2=temp2x; };
    if (temp2x<=temp1x) { Bx2=temp1x; };
    if (temp2y >temp1y) { By2=temp2y; };
    if (temp2y<=temp1y) { By2=temp1y; };
	//calcula a colisao
	if (
	(Ax1+(Ax2-Ax1)>Bx1) and
  (Ax1<Bx1+(Bx2-Bx1)) and 
  (Ay1+(Ay2-Ay1)>By1) and 
  (Ay1<By1+(By2-By1)) )
  { colisao=1; } else { colisao=0; };
	
	draw_sprite(screen, buffer, 0, 0);
	clear(buffer);
  }
  destroy_bitmap(buffer);
  return 0;
}
END_OF_MAIN();
