// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_imagem.hpp"

int main()
{
    char data;
    Imagem screen;
    int width, height;
    int lim;
    string pixel;

    while (cin >> data)
    {
        switch (data)
        {
        case 'i':
            cin >> width >> height;
            screen.initialize_image(width, height);

            break;
        // To do: Segmentation Fault aqui!!!
        case 'p':
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < height; i++)
                {
                    cin >> pixel;
                    screen.fill(i, j, pixel);
                }
            }
            break;

        case 's':
            screen.show();

            break;
        case 'g':
            screen.to_grayscale();
            break;
        case 't':
            cin >> lim;
            screen.grayscale_thresholding(lim);
            break;
        case 'b':
            avaliacao_basica();
            break;
        }
    }

    return 0;
}