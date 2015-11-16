instrucao()
{
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* tela_instrucao = load_bitmap("sprites/InicioMenu/INSTRUCAO.bmp", NULL);

    ///GAME LOOP
    while (!(key[KEY_ESC]))
    {
        draw_sprite(buffer, tela_instrucao, 0, 0);
        draw_sprite(screen, buffer, 0, 0);

        keyboard_input();

        //INPUT
        if (key[KEY_SPACE])
        {
            menu();
        }
    }
    ///FINALIZACAO
    destroy_bitmap(tela_instrucao);
    destroy_bitmap(buffer);

} END_OF_FUNCTION(instrucao);
