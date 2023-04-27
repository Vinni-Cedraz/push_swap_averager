#include <stdlib.h>

typedef unsigned int t_uint;
typedef unsigned char t_uc;

static void *aux_memchr(const void *s, int c, size_t n);
static char *aux_strrchr(const char *s, int c);
static size_t aux_strlen(const char *str);
static size_t aux_ft_strlen(const char *str);
static void *aux_ft_calloc(size_t nmemb, size_t size);
static void *aux_ft_memcpy(void *dst, const void *src, size_t n);
static char *ft_substr(char const *s, unsigned int start, size_t len);

char *ft_strtrim(char const *s1, char const *set) {
    int i;
    int j;
    int set_len;

    if (!s1 || !set) return (NULL);
    i = 0;
    j = aux_strlen(s1);
    set_len = aux_strlen(set);
    while (aux_memchr(set, s1[i], set_len)) i++;
    while (aux_strrchr(set, s1[j - 1])) j--;
    return (ft_substr(s1, i, j - i));
}

static char *ft_substr(char const *s, unsigned int start, size_t len) {
    char *substr;
    size_t s_len;

    s_len = (t_uint)aux_ft_strlen(s);
    if (start > s_len)
        return ((char *)aux_ft_calloc(1, sizeof(char)));
    else if (len > s_len - start) {
        substr = malloc((s_len - start + 1) * sizeof(char));
        aux_ft_memcpy(substr, s + start, s_len - start);
        substr[s_len - start] = '\0';
        return (substr);
    } else {
        substr = malloc((len + 1) * sizeof(char));
        aux_ft_memcpy(substr, s + start, len);
        substr[len] = '\0';
        return (substr);
    }
}

static inline void *aux_ft_memcpy(void *dst, const void *src, size_t n) {
    size_t i;

    i = -1;
    while (++i < n) *(((t_uc *)dst) + i) = *(((t_uc *)src) + i);
    return (dst);
}

static inline size_t aux_ft_strlen(const char *str) {
    size_t i;

    i = 0;
    while (str && *(str + i)) i++;
    return (i);
}

static inline void *aux_ft_calloc(size_t nmemb, size_t size) {
    char *ptr;
    size_t i;

    i = 0;
    if (!size || !nmemb) return (malloc(0));
    if (nmemb > __SIZE_MAX__ / size) return (NULL);
    ptr = malloc(size * nmemb);
    while (i < size * nmemb) {
        ptr[i] = 0;
        i++;
    }
    return (ptr);
}

static inline size_t aux_strlen(const char *str) {
    size_t i;

    i = 0;
    while (str && *(str + i)) i++;
    return (i);
}

static inline char *aux_strrchr(const char *s, int c) {
    int i;

    i = aux_strlen(s) + 1;
    while (i-- > 0 && s)
        if (s[i] == (char)c) return ((char *)s + i);
    return (NULL);
}

static inline void *aux_memchr(const void *s, int c, size_t n) {
    unsigned char chr;
    unsigned char *str;

    chr = (unsigned char)c;
    str = (unsigned char *)s;
    if (!str) return (NULL);
    while (n--)
        if (*str++ == chr) return (str - 1);
    return (NULL);
}
