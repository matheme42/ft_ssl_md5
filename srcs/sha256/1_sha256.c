
#include "sha256.h"

void sha256(char **av)
{
    int         option;
    t_option    complexe;
    size_t      file_size;
    char        *str_file;
    char        *hash;

    av = sha256_get_option(av, &option, &complexe);

    if (H)
        sha256_usage();

    if ((str_file = get_file_from_standard_entry(&file_size, P || (!*av && !complexe.s))))
    {
        str_file[file_size - 1] = '\0';
        hash = sha256_algo(option, file_size, str_file);
        sha256_output(!P ? "stdin" : str_file, hash, option);
        free(str_file);
        free(hash);
    }

    if (complexe.s)
    {
        file_size = ft_strlen(complexe.s);
        hash = sha256_algo(option, file_size, complexe.s);
        sha256_output(complexe.s, hash, option);
        free(hash);
    }
    
    while (*av)
    {
        if ((str_file = get_file_from_fd(try_get_fd_from_string(*av), &file_size)))
        {
            hash = sha256_algo(option, file_size, str_file);
            sha256_output(*av, hash, option);
            free(str_file);
            free(hash);
        }
        av = &av[1];
    }
}
