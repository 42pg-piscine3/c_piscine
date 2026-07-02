/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 09:21:40 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/02 09:34:51 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    ft_strlen(char *str)                                            
{                                                                               
    unsigned int    len;                                                        
    len = 0;                                                                    
    while (*str)                                                                
    {                                                                           
        str++;                                                                  
        len++;                                                                  
    }                                                                           
    return (len);                                                               
}                                                                               
                                                                                
char *ft_strncat(char *dest, char *src, unsigned int nb)
{                                                                               
    unsigned int    dlen;                                                       
    unsigned int    i;                                                          
                                                                                
    dlen = ft_strlen(dest);                                                     
    i = 0;                                                                      
    while (*src && i < nb)
    {                  		
        *(dest + dlen + i) = *src;                                              
        src++;                                                                  
        i++;                                                                    
    }                                                                           
    *(dest + dlen + i) = '\0';                                                  
                                                                                
    return (dest);                                                              
} 
