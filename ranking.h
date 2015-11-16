edicao_ranking(int contador)
{
    int primeiro_lugar, segundo_lugar, terceiro_lugar;
    int i;

    FILE *primeiro;
    FILE *segundo;
    FILE *terceiro;

    primeiro = fopen ("primeiro.txt", "r");
    segundo = fopen ("segundo.txt", "r");
    terceiro = fopen ("terceiro.txt", "r");

    fscanf (primeiro, "%d", &primeiro_lugar);
    fscanf (segundo, "%d", &segundo_lugar);
    fscanf (terceiro, "%d", &terceiro_lugar);

    i = segundo_lugar;

    if (contador < primeiro_lugar && contador < segundo_lugar && contador < terceiro_lugar)
    {
        i = segundo_lugar;
        terceiro_lugar = i;
        segundo_lugar = primeiro_lugar;
        primeiro_lugar = contador;

    } else if (contador > primeiro_lugar && contador < segundo_lugar && contador < terceiro_lugar)
    {
        terceiro_lugar = segundo_lugar;
        segundo_lugar = contador;

    } else if (contador > primeiro_lugar && contador > segundo_lugar && contador < terceiro_lugar)
    {
        terceiro_lugar = contador;
    }

    fclose (primeiro);
    fclose (segundo);
    fclose (terceiro);

    primeiro = fopen ("primeiro.txt", "w+");
    segundo = fopen ("segundo.txt", "w+");
    terceiro = fopen ("terceiro.txt", "w+");

    fprintf (primeiro, "%d\n", primeiro_lugar);
    fprintf (segundo, "%d\n", segundo_lugar);
    fprintf (terceiro, "%d\n", terceiro_lugar);

    fclose(primeiro);
    fclose(segundo);
    fclose(terceiro);

    return 0;

} END_OF_FUNCTION(edicao_ranking);


ranking()
{
    edicao_ranking(contador_movimento_total);

    int primeiro_lugar, segundo_lugar, terceiro_lugar;

    FILE *primeiro;
    FILE *segundo;
    FILE *terceiro;

    primeiro = fopen ("primeiro.txt", "r");
    segundo = fopen ("segundo.txt", "r");
    terceiro = fopen ("terceiro.txt", "r");

    fscanf (primeiro, "%d", &primeiro_lugar);
    fscanf (segundo, "%d", &segundo_lugar);
    fscanf (terceiro, "%d", &terceiro_lugar);

    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* tela_ranking = load_bitmap("sprites/InicioMenu/RANKING.bmp", NULL);

    ///GAME LOOP
    while (!(key[KEY_ESC]))
    {
        draw_sprite(buffer, tela_ranking, 0, 0);

        textprintf_ex(buffer, font, 395, 190, makecol(51, 51, 51), -1, "%d", primeiro_lugar);
        textprintf_ex(buffer, font, 395, 260, makecol(51, 51, 51), -1, "%d", segundo_lugar);
        textprintf_ex(buffer, font, 395, 330, makecol(51, 51, 51), -1, "%d", terceiro_lugar);

        draw_sprite(screen, buffer, 0, 0);

        keyboard_input();

        //INPUT
        if (key[KEY_SPACE])
        {
            menu();
        }
    }
    ///FINALIZACAO
    fclose (primeiro);
    fclose(segundo);
    fclose(terceiro);

    destroy_bitmap(tela_ranking);
    destroy_bitmap(buffer);

} END_OF_FUNCTION(ranking);
