#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>

using namespace std;

int MenuGlowne()
{
	string sWyborMenuGlowne;
	short siWybor = 0;



	do
	{

		cout << "\n\n\n\n\n\n\t\tWitaj w Into the darkness" << endl;
		cout << "\n\n\t1.Zagraj" << endl;
		cout << "\t2.Pomoc" << endl;
		cout << "\t3.Informacje" << endl;
		cout << "\t4.Wyjscie" << endl;

		cin >> sWyborMenuGlowne;
		system("cls");

	} while (!(sWyborMenuGlowne == "1" || sWyborMenuGlowne == "2" || sWyborMenuGlowne == "3" || sWyborMenuGlowne == "4"));
	siWybor = stoi(sWyborMenuGlowne);
	//cout << siWybor;
	return siWybor;
}
void Pozegnanie()
{
	system("cls");
	cout << "\n\n\n\n\n\n\t\tMilego Dnia\n\n\n\n\n\n";
	system("timeout 5");
}



int main()
{
	

	for (;;)
	{
		switch (MenuGlowne())
		{
		case 1:
		{
			
			bool draw = true;
			bool done = false;
			int poz_x = 400;
			int poz_y = 400;
			int poz_x2 = 300;
			int poz_y2 = 300;
			int counter = 0;
			const int WIDTH = 800;
		    const int HEIGHT = 600;
			const int FPS = 60;
			int moveSpeed = 5;
			enum direction { UP, DOWN, LEFT, RIGHT, S, W, A, D};
			int dir = DOWN;
			int kierunek = 1;
			int kierunek2 = 5;
			al_init_primitives_addon();

			if (!al_init())
			{
				fprintf(stderr, "Failed to initialize Allegro.\n");
				return -1;
			}

			al_install_keyboard();
			al_init_font_addon(); // initialize the font addon
			al_init_ttf_addon();// initialize the ttf (True Type Font) addon
			al_init_image_addon();

			ALLEGRO_DISPLAY *display = al_create_display(WIDTH, HEIGHT);
			al_set_window_position(display, 200, 100);
			al_set_window_title(display, "Into the darkness");
			
			ALLEGRO_BITMAP *czolk = NULL;
			ALLEGRO_BITMAP *czolk_S = NULL;
			ALLEGRO_BITMAP *czolk_A = NULL;
			ALLEGRO_BITMAP *czolk_D = NULL;
			ALLEGRO_BITMAP *czolk2 = NULL;
			ALLEGRO_BITMAP *czolk2_D = NULL;
			ALLEGRO_BITMAP *czolk2_A = NULL;
			ALLEGRO_BITMAP *czolk2_S = NULL;
			ALLEGRO_BITMAP *tlo = NULL;
			ALLEGRO_FONT *font = al_load_ttf_font("comic.ttf", 12, 0);
			ALLEGRO_KEYBOARD_STATE keyState;
			

			if (!display)
			{
				fprintf(stderr, "Failed to create display.\n");
				return -1;
			}
			
			if (!font)
			{
				fprintf(stderr, "Could not load 'comic.ttf'.\n");
				return -1;
			}

			//timer
			ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
			ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
			al_register_event_source(event_queue, al_get_keyboard_event_source());
			al_register_event_source(event_queue, al_get_timer_event_source(timer));

			al_start_timer(timer);

			//    Wczytywanie bit map
			czolk = al_load_bitmap("czolk.bmp");
			al_convert_mask_to_alpha(czolk, al_map_rgb(0, 0, 0));
			czolk2 = al_load_bitmap("czolk2.bmp");
			al_convert_mask_to_alpha(czolk2, al_map_rgb(0, 0, 0));
			tlo = al_load_bitmap("tlo.bmp");
			al_clear_to_color(al_map_rgb(0, 0, 0));
			czolk_S = al_load_bitmap("czolk_S.bmp");
			al_convert_mask_to_alpha(czolk_S, al_map_rgb(0, 0, 0));
			czolk_D = al_load_bitmap("czolk_D.bmp");
			al_convert_mask_to_alpha(czolk_D, al_map_rgb(0, 0, 0));
			czolk_A = al_load_bitmap("czolk_A.bmp");
			al_convert_mask_to_alpha(czolk_A, al_map_rgb(0, 0, 0));
			czolk2_A = al_load_bitmap("czolk2_A.bmp");
			al_convert_mask_to_alpha(czolk2_A, al_map_rgb(0, 0, 0));
			czolk2_S = al_load_bitmap("czolk2_S.bmp");
			al_convert_mask_to_alpha(czolk2_S, al_map_rgb(0, 0, 0));
			czolk2_D = al_load_bitmap("czolk2_D.bmp");
			al_convert_mask_to_alpha(czolk2_D, al_map_rgb(0, 0, 0));

			while (!done)
			{
				draw = true;

				al_draw_bitmap(tlo, 0, 0, 0);

				ALLEGRO_EVENT ev;
				al_wait_for_event(event_queue, &ev);

				if (ALLEGRO_EVENT_KEY_UP && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
					done = true;
				//                         MUFMENT
				if (ev.type == ALLEGRO_EVENT_TIMER)
				{
					al_get_keyboard_state(&keyState);
					if (al_key_down(&keyState, ALLEGRO_KEY_UP))
					{
						kierunek = 1;
						poz_y -= moveSpeed;
					}
					if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
					{
						kierunek = 2;
						poz_x += moveSpeed;
					}
					if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
					{
						kierunek = 3;
						poz_x -= moveSpeed;
					}
					if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
					{
						kierunek = 4;
						poz_y += moveSpeed;
					}
					if (al_key_down(&keyState, ALLEGRO_KEY_W))
					{
						kierunek2 = 5;
						poz_y2 -= moveSpeed;
					}
					if (al_key_down(&keyState, ALLEGRO_KEY_D))
					{
						kierunek2 = 6;
						poz_x2 += moveSpeed;
					}
					if (al_key_down(&keyState, ALLEGRO_KEY_A))
					{
						kierunek2 = 7;
						poz_x2 -= moveSpeed;
					}
					if (al_key_down(&keyState, ALLEGRO_KEY_S))
					{
						kierunek2 = 8;
						poz_y2 += moveSpeed;
					}
					draw = true;
				
				}
				//                  Rysowanie
				if (draw)
				{
					draw = false;
					if (kierunek == 1)
					{	
						al_draw_bitmap(czolk, poz_x, poz_y, 0);
					}
					else if (kierunek == 2)
					{
						al_draw_bitmap(czolk_D, poz_x, poz_y, 0);
					}
					else if (kierunek == 3)
					{
						al_draw_bitmap(czolk_A, poz_x, poz_y, 0);
					}
					else if (kierunek == 4)
					{
						al_draw_bitmap(czolk_S, poz_x, poz_y, 0);
					}
					if (kierunek2 == 5)
					{
						al_draw_bitmap(czolk2, poz_x2, poz_y2, 0);
					}
					else if (kierunek2 == 6)
					{
						al_draw_bitmap(czolk2_D, poz_x2, poz_y2, 0);
					}
					else if (kierunek2 == 7)
					{
						al_draw_bitmap(czolk2_A, poz_x2, poz_y2, 0);
					}
					else if (kierunek2 == 8)
					{
						al_draw_bitmap(czolk2_S, poz_x2, poz_y2, 0);
					}
				    al_draw_textf(font, al_map_rgb(0, 255, 0), 50, 5, ALLEGRO_ALIGN_CENTRE, "Odswiezanie: %i", counter);
				    al_flip_display();
			    }

				//         Kolizja z koncem mapy
				if (poz_x >= WIDTH - 50)
					poz_x = WIDTH - 50;
				else if (poz_x <= 0)
				    poz_x = 0;

				if (poz_y >= HEIGHT - 50)
					poz_y = HEIGHT - 50;
				else if (poz_y <= 0)
				    poz_y = 0;

				if (poz_x2 >= WIDTH - 50)
					poz_x2 = WIDTH - 50;
				else if (poz_x2 <= 0)
					poz_x2 = 0;

				if (poz_y2 >= HEIGHT - 50)
					poz_y2 = HEIGHT - 50;
				else if (poz_y2 <= 0)

					poz_y2 = 0;
			}
			al_destroy_event_queue(event_queue);
			al_destroy_display(display);
			al_destroy_timer(timer);

			return 0;
		}


			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			Pozegnanie();
			return EXIT_SUCCESS;
		}
	}
}


