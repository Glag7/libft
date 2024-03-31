/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glag <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:23:38 by glag              #+#    #+#             */
/*   Updated: 2024/03/31 23:55:23 by glag             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

# include <stdint.h>
# include <stdbool.h>

# define TOO_BIG -128

# define ASCII 1
# define PRINT 2
# define LOWER 4
# define UPPER 8
# define SPACE 16
# define DIGIT 32
# define XDIGIT 64
# define PUNCT 128

# define ALPHA LOWER | UPPER
# define ALNUM ALPHA | DIGIT

# define C000 ASCII
# define C001 ASCII
# define C002 ASCII
# define C003 ASCII
# define C004 ASCII
# define C005 ASCII
# define C006 ASCII
# define C007 ASCII
# define C008 ASCII
# define C009 ASCII | SPACE
# define C010 ASCII | SPACE
# define C011 ASCII | SPACE
# define C012 ASCII | SPACE
# define C013 ASCII | SPACE
# define C014 ASCII
# define C015 ASCII
# define C016 ASCII
# define C017 ASCII
# define C018 ASCII
# define C019 ASCII
# define C020 ASCII
# define C021 ASCII
# define C022 ASCII
# define C023 ASCII
# define C024 ASCII
# define C025 ASCII
# define C026 ASCII
# define C027 ASCII
# define C028 ASCII
# define C029 ASCII
# define C030 ASCII
# define C031 ASCII
# define C032 ASCII | PRINT | SPACE
# define C033 ASCII | PRINT | PUNCT
# define C034 ASCII | PRINT | PUNCT
# define C035 ASCII | PRINT | PUNCT
# define C036 ASCII | PRINT | PUNCT
# define C037 ASCII | PRINT | PUNCT
# define C038 ASCII | PRINT | PUNCT
# define C039 ASCII | PRINT | PUNCT
# define C040 ASCII | PRINT | PUNCT
# define C041 ASCII | PRINT | PUNCT
# define C042 ASCII | PRINT | PUNCT
# define C043 ASCII | PRINT | PUNCT
# define C044 ASCII | PRINT | PUNCT
# define C045 ASCII | PRINT | PUNCT
# define C046 ASCII | PRINT | PUNCT
# define C047 ASCII | PRINT | PUNCT
# define C048 ASCII | PRINT | DIGIT | XDIGIT
# define C049 ASCII | PRINT | DIGIT | XDIGIT
# define C050 ASCII | PRINT | DIGIT | XDIGIT
# define C051 ASCII | PRINT | DIGIT | XDIGIT
# define C052 ASCII | PRINT | DIGIT | XDIGIT
# define C053 ASCII | PRINT | DIGIT | XDIGIT
# define C054 ASCII | PRINT | DIGIT | XDIGIT
# define C055 ASCII | PRINT | DIGIT | XDIGIT
# define C056 ASCII | PRINT | DIGIT | XDIGIT
# define C057 ASCII | PRINT | DIGIT | XDIGIT
# define C058 ASCII | PRINT | PUNCT
# define C059 ASCII | PRINT | PUNCT
# define C060 ASCII | PRINT | PUNCT
# define C061 ASCII | PRINT | PUNCT
# define C062 ASCII | PRINT | PUNCT
# define C063 ASCII | PRINT | PUNCT
# define C064 ASCII | PRINT | PUNCT
# define C065 ASCII | PRINT | UPPER | XDIGIT
# define C066 ASCII | PRINT | UPPER | XDIGIT
# define C067 ASCII | PRINT | UPPER | XDIGIT
# define C068 ASCII | PRINT | UPPER | XDIGIT
# define C069 ASCII | PRINT | UPPER | XDIGIT
# define C070 ASCII | PRINT | UPPER | XDIGIT
# define C071 ASCII | PRINT | UPPER
# define C072 ASCII | PRINT | UPPER
# define C073 ASCII | PRINT | UPPER
# define C074 ASCII | PRINT | UPPER
# define C075 ASCII | PRINT | UPPER
# define C076 ASCII | PRINT | UPPER
# define C077 ASCII | PRINT | UPPER
# define C078 ASCII | PRINT | UPPER
# define C079 ASCII | PRINT | UPPER
# define C080 ASCII | PRINT | UPPER
# define C081 ASCII | PRINT | UPPER
# define C082 ASCII | PRINT | UPPER
# define C083 ASCII | PRINT | UPPER
# define C084 ASCII | PRINT | UPPER
# define C085 ASCII | PRINT | UPPER
# define C086 ASCII | PRINT | UPPER
# define C087 ASCII | PRINT | UPPER
# define C088 ASCII | PRINT | UPPER
# define C089 ASCII | PRINT | UPPER
# define C090 ASCII | PRINT | UPPER
# define C091 ASCII | PRINT | PUNCT
# define C092 ASCII | PRINT | PUNCT
# define C093 ASCII | PRINT | PUNCT
# define C094 ASCII | PRINT | PUNCT
# define C095 ASCII | PRINT | PUNCT
# define C096 ASCII | PRINT | PUNCT
# define C097 ASCII | PRINT | LOWER | XDIGIT
# define C098 ASCII | PRINT | LOWER | XDIGIT
# define C099 ASCII | PRINT | LOWER | XDIGIT
# define C100 ASCII | PRINT | LOWER | XDIGIT
# define C101 ASCII | PRINT | LOWER | XDIGIT
# define C102 ASCII | PRINT | LOWER | XDIGIT
# define C103 ASCII | PRINT | LOWER
# define C104 ASCII | PRINT | LOWER
# define C105 ASCII | PRINT | LOWER
# define C106 ASCII | PRINT | LOWER
# define C107 ASCII | PRINT | LOWER
# define C108 ASCII | PRINT | LOWER
# define C109 ASCII | PRINT | LOWER
# define C110 ASCII | PRINT | LOWER
# define C111 ASCII | PRINT | LOWER
# define C112 ASCII | PRINT | LOWER
# define C113 ASCII | PRINT | LOWER
# define C114 ASCII | PRINT | LOWER
# define C115 ASCII | PRINT | LOWER
# define C116 ASCII | PRINT | LOWER
# define C117 ASCII | PRINT | LOWER
# define C118 ASCII | PRINT | LOWER
# define C119 ASCII | PRINT | LOWER
# define C120 ASCII | PRINT | LOWER
# define C121 ASCII | PRINT | LOWER
# define C122 ASCII | PRINT | LOWER
# define C123 ASCII | PRINT | PUNCT
# define C124 ASCII | PRINT | PUNCT
# define C125 ASCII | PRINT | PUNCT
# define C126 ASCII | PRINT | PUNCT
# define C127 ASCII

bool	ft_is(int bitmask, int c);

#endif
