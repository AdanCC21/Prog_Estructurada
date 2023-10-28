/*Gonzalez Ceseña Adan 372799
Función en C que pida el mes y día de nacimiento de una persona y el programa le despliega el signo del zodiaco que le corresponde y su correspondiente horoscopo del Dia.
09/10/2024
Actv_3_7_932*/
#include <stdio.h>
int main()
{
    int di, me;
    printf("Bienveido, ingrese su dia de nacimiento\n");
    scanf("%d",&di);
    printf("Porfavor escriba su mes en numero\n");
    scanf("%d",&me);
    if(me>=7)
    {
        if(me>=8)
        {
            if(me>=9)
            {
                if(me>=10)
                {
                    if(me>=11)
                    {
                        if(me==12)
                        {
                            if(di>=1 && di<=21)
                            {
                                printf("Sagirario\n");
                                printf("¿Te ha tocado alguna vez la lotería? ¡Seguro! Estás tan acostumbrada a tener la suerte de tu lado que todo al que haces daño te acaba perdonando. Tu misión para 2023 es aprender a comunicarte mejor. Eso sí, no lo hagas en Mercurio retro.");
                            }
                            else
                            {
                                printf("capricornio\n");
                                printf("Mientras que el ámbito del amor se mantendrá tranquilo (o inexistente) durante 2023, el del trabajo te puede dar grandes alegrías. Aprovecha desde el primer día del año para buscar el empleo que siempre has soñado y no tengas miedo de irte fuera.");
                            }
                            return 0;
                        }
                        if(di>=1 && di<=21)
                        {
                            printf("Escorpio\n");
                            printf("2023 se convierte en el momento perfecto para, ahora que tienes tu vida establecida, mejorarla a través de inversiones. Estas pueden ser un coche o cambios en tu hogar. No debes seguir gastándote el sueldo en copas todos los fines de semana.");
                        }
                        else
                        {
                            printf("Sagitario\n");
                            printf("¿Te ha tocado alguna vez la lotería? ¡Seguro! Estás tan acostumbrada a tener la suerte de tu lado que todo al que haces daño te acaba perdonando. Tu misión para 2023 es aprender a comunicarte mejor. Eso sí, no lo hagas en Mercurio retro.");
                        }
                        return 0;
                    }
                    if(di>=1&& di<=22)
                    {
                        printf("Libra\n");
                        printf("Los amigos serán tu gran apoyo en este año de cambios que te esperan. Siempre has sido una persona muy correcta, pero con la entrada de Plutón en Acuario sentirás que tus valores ya no maridan con tu personalidad. Los que te quieren seguirán estando para ti");
                    }
                    else
                    {
                        printf("Escorpio\n");
                        printf("2023 se convierte en el momento perfecto para, ahora que tienes tu vida establecida, mejorarla a través de inversiones. Estas pueden ser un coche o cambios en tu hogar. No debes seguir gastándote el sueldo en copas todos los fines de semana.");
                    }
                    return 0;
                }
                if(di>=1 && di<=22)
                {
                    printf("Virgo\n");
                    printf("Salir de fiesta y beberse hasta el agua de los floreros ya no está de moda. Solo que ahora te has dado cuenta de que todo tu círculo lleva este rollo que ya no se identifica contigo. Encontrarás nuevos círculos, si pruebas nuevos hobbies y te arriesgas.");
                }
                else
                {
                    printf("Libra\n");
                    printf("Los amigos serán tu gran apoyo en este año de cambios que te esperan. Siempre has sido una persona muy correcta, pero con la entrada de Plutón en Acuario sentirás que tus valores ya no maridan con tu personalidad. Los que te quieren seguirán estando para ti.");
                }
                return 0;
            }
            if(di>=1 && di<=22)
            {
              printf("Leo\n");
              printf("Tu vida amorosa estará en ‘stand-by’ hasta que llegue el verano. Con Venus retrogradando del 23 de julio al 4 de septiembre, ligarás un montón, pero nadie conseguirá llevarse el premio de tener una segunda cita.");  
            }
            else
            {
                printf("Virgo\n");
                printf("Salir de fiesta y beberse hasta el agua de los floreros ya no está de moda. Solo que ahora te has dado cuenta de que todo tu círculo lleva este rollo que ya no se identifica contigo. Encontrarás nuevos círculos, si pruebas nuevos hobbies y te arriesgas.");
            }
            return 0;
        }
        if(di>=1 && di<=22)
        {
            printf("Cancer\n");
            printf("Te cuesta soltar, es un hecho, y probablemente no te deshagas de esa relación tóxica que no te aporta nada hasta el final de la temporada de eclipses. Esto será el 28 de octubre, con uno de tipo lunar sobre Tauro. Cuídate mucho hasta entonces.");
        }
        else
        {
            printf("Leo\n");
            printf("Tu vida amorosa estará en ‘stand-by’ hasta que llegue el verano. Con Venus retrogradando del 23 de julio al 4 de septiembre, ligarás un montón, pero nadie conseguirá llevarse el premio de tener una segunda cita.");
        }
        return 0;
    }
    if(me<=6)
    {
        if(me<=5)
        {
            if(me<=4)
            {
                if(me<=3)
                {
                    if(me<=2)
                    {
                        if(me<=1)
                        {
                            if(di>=1&&di<=19)
                            {
                                printf("Capricornio\n");
                                printf("Mientras que el ambito del amor se mantendra tranquilo (o anexistente) durante 2023, el del trabajo te puede dar grandes alegrias. Aprovecha desde el primer dia del tiempo para buscar el empleo que siempre has sonado y no tengas miedo de irte fuera.");
                            }
                            else
                            {
                                printf("Acuario\n");
                                printf("Tendrás compañero de piso nuevo, porque Plutón estará casi todo el año en tu constelación. Ojo porque es el planeta de la transformación, por lo que es probable que tu vida se convierta en un plot twist constante. Te lo pasarás bien, ya verás.");
                            }
                            return 0;
                        }
                        if(di>=1&&di<=18)
                        {
                            printf("Acuario\n");
                            printf("Tendrás compañero de piso nuevo, porque Plutón estará casi todo el año en tu constelación. Ojo porque es el planeta de la transformación, por lo que es probable que tu vida se convierta en un plot twist constante. Te lo pasarás bien, ya verás.");
                        }
                        else
                        {
                            printf("Piscis\n");
                            printf("Te cuesta reconocer tus errores y acabas sintiéndote víctima de tu propia vida. Pues bien, 2023 es el año de pasar del género drama al género responsabilidad. Sobre todo porque siempre hay alguien que está peor que tú. Sé más agradecida con lo que tienes.");
                        }
                        return 0;
                    }
                    if(di>=1 && di<=20)
                    {
                        printf("Piscis\n");
                        printf("Te cuesta reconocer tus errores y acabas sintiéndote víctima de tu propia vida. Pues bien, 2023 es el año de pasar del género drama al género responsabilidad. Sobre todo porque siempre hay alguien que está peor que tú. Sé más agradecida con lo que tienes.");
                    }
                    else
                    {
                        printf("Aries\n");
                        printf("Apunta bien el plan. Los primeros meses del año serán el momento de organizar y proyectar tus objetivos a cumplir a lo largo de 2023. ¡Pero nada de llevarlos a cabo! Esto lo harás una vez suceda el eclipse solar sobre Aries del 20 de abril.");
                    }
                    return 0;
                }
                if(di>=1 && di<=19)
                {
                    printf("Aries\n");
                    printf("Apunta bien el plan. Los primeros meses del año serán el momento de organizar y proyectar tus objetivos a cumplir a lo largo de 2023. ¡Pero nada de llevarlos a cabo! Esto lo harás una vez suceda el eclipse solar sobre Aries del 20 de abril.");
                }
                else
                {
                    printf("Tauro");
                    printf("Si deseas hacer grandes cambios de tu vida, como independizarte, casarte o marcharte de tu ciudad, hazlo unos meses antes de la llegada del verano. De abril a junio habrá una gran cantidad de planetas ayudando a tu constelación.");
                }
                return 0;
            }
            if(di>=1 && di<=20)
            {
                printf("Tauro\n");
                printf("Si deseas hacer grandes cambios de tu vida, como independizarte, casarte o marcharte de tu ciudad, hazlo unos meses antes de la llegada del verano. De abril a junio habrá una gran cantidad de planetas ayudando a tu constelación.");
            }
            else
            {
                printf("Geminis\n");
                printf("2023 será el año más largo de tu vida, y la razón no es otra que lo tranquila que te sentirás durante todos los doce meses. No está mal y te vendrá bien para cuidar tu salud mental. Esta nueva tú te ayudará en ámbitos de tu vida que no creías importantes.");
            }
            return 0;
        }
        if(di>=1 && di<=20)
        {
            printf("Geminis\n");
            printf("2023 será el año más largo de tu vida, y la razón no es otra que lo tranquila que te sentirás durante todos los doce meses. No está mal y te vendrá bien para cuidar tu salud mental. Esta nueva tú te ayudará en ámbitos de tu vida que no creías importantes.");
        }
        else
        {
            printf("Cancer\n");
            printf("Te cuesta soltar, es un hecho, y probablemente no te deshagas de esa relación tóxica que no te aporta nada hasta el final de la temporada de eclipses. Esto será el 28 de octubre, con uno de tipo lunar sobre Tauro. Cuídate mucho hasta entonces.");
        }
        return 0;
    }
}