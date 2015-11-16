volatile int exit_program = FALSE;

void keyboard_input()
{
    int x;

    for(x = 0; x < KEY_MAX; x++)
        teclas_anteriores[x] = key[x];

    poll_keyboard();
}

int apertou(int TECLA)
{
    return(teclas_anteriores[TECLA] == 0 && key[TECLA] != 0);
}

int segurou(int TECLA)
{
    return(teclas_anteriores[TECLA] != 0 && key[TECLA] != 0);
}

int soltou(int TECLA)
{
    return(teclas_anteriores[TECLA] != 0 && key[TECLA] == 0);
}

void fecha_programa()
{
    exit_program = TRUE;
} END_OF_FUNCTION(fecha_programa);

void close_program()
{
    exit_program = TRUE;
} END_OF_FUNCTION(close_program);

void inicializacao()
{
    allegro_init();
    install_timer();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 450, 0, 0);
    set_window_title("Breaking Sokoban");

    LOCK_VARIABLE(exit_program);
    LOCK_FUNCTION(close_program);

    set_close_button_callback(close_program);

    INICIO();

} END_OF_FUNCTION(inicializacao);

INICIO()
{
    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* tela_inicio = load_bitmap("sprites/InicioMenu/INICIAL.bmp", NULL);

    ///GAME LOOP
    while(!exit_program)
    {
        //INPUT
        keyboard_input();

        if(key[KEY_ESC])
        {
            fecha_programa();
        }

        if(key[KEY_SPACE])
        {
            menu();
        }
        //DRAW
        draw_sprite(buffer, tela_inicio, 0, 0);
        draw_sprite(screen, buffer, 0, 0);
        clear_to_color(buffer, makecol(255,255,255));
    }
    ///FINALIZACAO
    destroy_bitmap(tela_inicio);
    destroy_bitmap(buffer);

} END_OF_FUNCTION(INICIO);

