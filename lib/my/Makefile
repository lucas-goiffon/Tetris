##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Make for libmy.a.
##

SRC		=		concat_params.c             \
                my_putchar.c                \
                my_strcapitalize.c          \
                my_str_isnum.c              \
                my_strncpy.c                \
                my_put_nbr.c                \
                my_put_nbr_error.c          \
                my_strcat.c                 \
                my_str_isprintable.c        \
                my_strstr.c                 \
                my_compute_power_rec.c      \
                my_putstr.c                 \
                my_putstr_error.c           \
                my_strcmp.c                 \
                my_str_isupper.c            \
                my_strupcase.c              \
                my_find_prime_sup.c         \
                my_revstr.c                 \
                my_strcpy.c                 \
                my_strlen.c                 \
                my_swap.c                   \
                my_getnbr.c                 \
                my_showmem.c                \
                my_strdup.c                 \
                my_strlowcase.c             \
                my_isneg.c                  \
                my_showstr.c                \
                my_str_isalpha.c            \
                my_strncat.c                \
                my_is_prime.c               \
                my_sort_int_array.c         \
                my_str_islower.c            \
                my_strncmp.c			    \
				my_printf.c                 \
                my_put_other_nbr.c          \
                conversions.c               \
                conversions_two.c           \
                s_upp_flag.c                \
                s_low_flag.c                \
                d_and_i_flags.c             \
                u_flag.c                    \
                ld_flag.c                   \
                c_flag.c                    \
                p_flag.c                    \
                x_low_flag.c                \
                x_upp_flag.c                \
                b_flag.c                    \
                o_flag.c                    \
                s_upp_call_flag.c           \
                mod_flag.c				    \
				nbsign_flag.c			    \
				spaces_delete_printf.c	    \
				hd_flag.c				    \
				my_int_to_str.c             \
                fill_str.c                  \
                my_strcat_two.c             \
                my_str_to_word_array.c      \
                my_str_to_word_array_two.c  \
                fill_str_two.c              \
                get_next_line.c             \
                destroy_double_array.c      \
                is_digits.c                 \
                is_alpha.c                  \
                my_malloc.c                 \
                my_tablen.c                 \
                print_double_array.c        \
                my_strcmp_maj.c

OBJ		=		$(SRC:.c=.o)

NAME	=		libmy.a

all:	$(NAME) clean

$(NAME):		$(OBJ)
		ar rc $(NAME) *.o

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all clean

auteur:
		echo $(USER) > LuCas
