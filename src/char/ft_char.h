/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glag <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:23:38 by glag              #+#    #+#             */
/*   Updated: 2024/04/01 00:33:56 by glag             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

# include <stdint.h>
# include <stdbool.h>

# define TOLOWER 223
# define TOUPPER 32

# define TOO_BIG -128

# define ASCII 1
# define PRINT 2
# define LOWER 4
# define UPPER 8
# define SPACE 16
# define DIGIT 32
# define XDIGIT 64
# define PUNCT 128
# define ALPHA 12
# define ALNUM 44

//norme doesn't allow for macros inside macros.
//as always, the code is much messier.
# define C000 1
# define C001 1
# define C002 1
# define C003 1
# define C004 1
# define C005 1
# define C006 1
# define C007 1
# define C008 1
# define C009 17
# define C010 17
# define C011 17
# define C012 17
# define C013 17
# define C014 1
# define C015 1
# define C016 1
# define C017 1
# define C018 1
# define C019 1
# define C020 1
# define C021 1
# define C022 1
# define C023 1
# define C024 1
# define C025 1
# define C026 1
# define C027 1
# define C028 1
# define C029 1
# define C030 1
# define C031 1
# define C032 19
# define C033 131
# define C034 131
# define C035 131
# define C036 131
# define C037 131
# define C038 131
# define C039 131
# define C040 131
# define C041 131
# define C042 131
# define C043 131
# define C044 131
# define C045 131
# define C046 131
# define C047 131
# define C048 99
# define C049 99
# define C050 99
# define C051 99
# define C052 99
# define C053 99
# define C054 99
# define C055 99
# define C056 99
# define C057 99
# define C058 131
# define C059 131
# define C060 131
# define C061 131
# define C062 131
# define C063 131
# define C064 131
# define C065 75
# define C066 75
# define C067 75
# define C068 75
# define C069 75
# define C070 75
# define C071 11
# define C072 11
# define C073 11
# define C074 11
# define C075 11
# define C076 11
# define C077 11
# define C078 11
# define C079 11
# define C080 11
# define C081 11
# define C082 11
# define C083 11
# define C084 11
# define C085 11
# define C086 11
# define C087 11
# define C088 11
# define C089 11
# define C090 11
# define C091 131
# define C092 131
# define C093 131
# define C094 131
# define C095 131
# define C096 131
# define C097 71
# define C098 71
# define C099 71
# define C100 71
# define C101 71
# define C102 71
# define C103 7
# define C104 7
# define C105 7
# define C106 7
# define C107 7
# define C108 7
# define C109 7
# define C110 7
# define C111 7
# define C112 7
# define C113 7
# define C114 7
# define C115 7
# define C116 7
# define C117 7
# define C118 7
# define C119 7
# define C120 7
# define C121 7
# define C122 7
# define C123 131
# define C124 131
# define C125 131
# define C126 131
# define C127 1

bool	ft_is(int bitmask, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
