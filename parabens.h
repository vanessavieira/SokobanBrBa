passou_fase()
{
    ///BITMAP
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

    while(!key[KEY_ESC])
    {
        if (fase_atual == 1)
        {
            rest(900);
            FASE_2();
        }
        else if (fase_atual == 2)
        {
            rest(900);
            FASE_3();
        }
        else if (fase_atual == 3)
        {
            parabens();
        }

        draw_sprite(screen, buffer, 0, 0);
        clear_to_color(buffer, makecol(255,255,255));
    }
    destroy_bitmap(buffer);

} END_OF_FUNCTION(passou_fase);

parabens()
{
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* tela_parabens = load_bitmap("sprites/Fases/parabens.bmp", NULL);

    while(!exit_program)
    {
        //DRAW
        draw_sprite(buffer, tela_parabens, 0, 0);
        textprintf_ex(buffer, font, 550, 330, makecol(51, 51, 51), -1, "%d", contador_movimento_total);

        //INPUT
        keyboard_input();

        if(key[KEY_ESC])
        {
            fecha_programa();
        }

        if(key[KEY_BACKSPACE])
        {
            ranking();
        }

        //DRAW
        draw_sprite(screen, buffer, 0, 0);
        clear_to_color(buffer, makecol(255,255,255));
    }

    destroy_bitmap(tela_parabens);
    destroy_bitmap(buffer);

} END_OF_FUNCTION(parabens);
