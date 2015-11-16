menu()
{
    int x = 110;
    int y = 130;

    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* menu = load_bitmap("sprites/InicioMenu/MENU.bmp", NULL);
    BITMAP* select = load_bitmap("sprites/InicioMenu/select.bmp", NULL);
    BITMAP* inicio_jogo = load_bitmap("sprites/InicioMenu/INICIAR_JOGO_INTRO.bmp", NULL);

    ///GAME LOOP
    while(!(key[KEY_ESC]))
    {
        //DRAW
        draw_sprite(buffer, menu, 0, 0);
        masked_blit(select, buffer, 0, 0, x, y, 320, 64);

        //INPUT
        keyboard_input();

        if (key[KEY_UP])
        {
            masked_blit(select, buffer, 0, 0, x, y -= 65, 32, 32);
            rest(125);
            if (y <= 130)
            {
                y = 130;
            }
        } else if(key[KEY_DOWN])
        {
            masked_blit(select, buffer, 0, 0, x, y += 65, 32, 32);
            rest(125);
            if (y >= 325)
            {
                y = 325;
            }
        }

         if (key[KEY_ENTER] && y == 325) //opcao sair do jogo
        {
            exit(0);
        }

        if (key[KEY_ENTER] && y == 260) //opcao ver ranking
        {
            ranking();
        }

        if (key[KEY_ENTER] && y == 195) //opcao ver instrucao
        {
            instrucao();
        }

        if (key[KEY_ENTER] && y == 130) //opcao iniciar jogo
        {
            draw_sprite(screen, inicio_jogo, 0, 0);
            rest(15000);
            FASE_1();
        }

        draw_sprite(screen, buffer, 0, 0);
        clear_to_color(buffer, makecol(255,255,255));
    }

    ///FINALIZACAO
    destroy_bitmap(menu);
    destroy_bitmap(select);
    destroy_bitmap(buffer);

} END_OF_FUNCTION(menu);
