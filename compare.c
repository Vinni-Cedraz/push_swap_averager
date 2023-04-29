#include <stddef.h>
#include <stdlib.h>
#include <string.h>
typedef struct s_plit
{
	char	*end;
	char	*start;
	char	**str_arr;
	size_t	words;

}			t_split;

int	ft_word_counter(char const *s, char c)
{
	int		counter;
	char	state;

	state = 0;
	counter = 0;
	while (*s)
	{
		if (*s != c && state == 0)
		{
			state = 1;
			counter++;
		}
		else if (*s == c)
			state = 0;
		s++;
	}
	return (counter);
}
static size_t	aux_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

static void	*aux_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = -1;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (++i < n)
		*(dest + i) = *(source + i);
	return (dest);
}

static char	*aux_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	unsigned int	s_len;

	s_len = (unsigned int)aux_strlen(s);
	if (start > s_len)
		return (malloc(0));
	else if (len > s_len - start)
	{
		substr = malloc((s_len - start + 1) * sizeof(char));
		aux_memcpy(substr, s + start, s_len - start);
		substr[s_len - start] = '\0';
		return (substr);
	}
	else
	{
		substr = malloc((len + 1) * sizeof(char));
		aux_memcpy(substr, s + start, len);
		substr[len] = '\0';
		return (substr);
	}
}

char *cmp(char *s1, char *s2) {
	while (*s1 == *s2)
		s1++, s2++;
	s1[3] = '\0';
	return (s1);
}

t_split	*ft_split(char const *s, char c)
{
	t_split	*tool;
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	tool = (t_split *)malloc(sizeof(t_split));
	tool->words = ft_word_counter(s, c);
	tool->start = (char *)s;
	tool->end = tool->start;
	tool->str_arr = (char **)calloc(tool->words + 1, sizeof(char *));
	while (++i < tool->words)
	{
		while (*tool->end == c && tool->end++)
			if (*tool->end != c)
				tool->start = tool->end;
		tool->end = memchr(tool->start, c, aux_strlen(tool->start));
		if (!tool->end)
			tool->end = tool->end + aux_strlen(tool->start);
		tool->str_arr[i] = aux_substr(tool->start, 0, tool->end - tool->start);
	}
	return (tool);
}


#include <stdio.h>
int main()
{
	char str1[] = "420 362 167 112 403 43 195 280 347 190 75 449 147 200 338 14 399 76 306 287 34 268 83 194 398 468 257 111 429 340 191 482 109 6 413 317 439 49 438 32 310 378 428 186 463 332 84 183 91 412 355 260 170 74 59 62 271 341 321 140 465 382 255 381 488 259 390 364 187 15 498 28 432 102 434 392 174 452 491 396 334 189 462 295 406 279 315 242 99 253 393 35 26 437 247 494 311 415 155 447 158 410 235 337 219 266 480 436 283 39 383 225 291 430 320 486 473 73 423 467 269 496 205 41 50 361 350 356 21 38 307 252 285 203 223 212 345 487 81 433 368 386 459 286 359 192 213 113 371 153 456 94 7 425 67 312 240 329 246 171 175 446 78 22 493 236 323 48 8 87 335 264 308 384 96 126 385 89 265 188 141 322 416 309 210 426 221 119 166 435 440 348 227 328 179 256 177 336 263 342 156 107 469 305 417 85 208 202 472 441 357 319 33 349 402 251 454 164 448 106 302 424 5 234 275 161 122 150 114 277 138 444 267 157 18 233 418 79 244 36 31 29 453 178 82 131 2 483 86 149 339 135 313 16 401 55 60 163 66 289 324 182 101 165 370 298 243 130 461 414 201 492 151 330 421 374 373 46 30 409 137 12 65 104 395 394 204 352 481 95 146 169 68 1 372 397 400 411 11 93 214 224 64 282 3 489 127 17 193 455 367 407 216 100 366 184 273 405 284 134 108 250 351 450 10 144 363 303 58 388 97 47 154 443 160 45 471 51 0 248 61 477 196 331 404 475 304 103 369 132 40 353 162 344 90 142 294 71 445 180 136 466 185 431 220 299 133 143 457 389 272 207 375 408 70 499 391 365 249 478 226 262 209 485 479 228 343 231 52 77 129 484 326 229 297 460 211 173 88 290 123 239 105 451 168 128 274 258 237 470 245 4 387 230 57 318 464 292 474 145 152 206 148 115 458 56 238 63 69 42 261 376 218 316 110 199 288 117 325 53 124 442 80 419 301 276 37 380 197 379 172 377 215 120 495 198 497 121 27 13 293 181 346 125 360 44 24 270 314 427 159 490 217 358 9 333 354 281 241 20 116 139 222 476 232 296 54 176 422 23 19 118 98 278 92 25 72 300 254 327";
	char str2[] = "420 362 167 112 403 43 195 280 347 190 75 449 147 200 338 14 399 76 306 287 34 268 83 194 398 468 257 111 429 340 191 482 109 6 413 317 439 49 438 32 310 378 428 186 463 332 84 183 91 412 355 260 170 74 59 62 271 341 321 140 465 382 255 381 488 259 390 364 187 15 498 28 432 102 434 392 174 452 491 396 334 189 462 295 406 279 315 242 99 253 393 35 26 437 247 494 311 415 155 447 158 410 235 337 219 266 480 436 283 39 383 225 291 430 320 486 473 73 423 467 269 496 205 41 50 361 350 356 21 38 307 252 285 203 223 212 345 487 81 433 368 386 459 286 359 192 213 113 371 153 456 94 7 425 67 312 240 329 246 171 175 446 78 22 493 236 323 48 8 87 335 264 308 384 96 126 385 89 265 188 141 322 416 309 210 426 221 119 166 435 440 348 227 328 179 256 177 336 263 342 156 107 469 305 417 85 208 202 472 441 357 319 33 349 402 251 454 164 448 106 302 424 5 234 275 161 122 150 114 277 138 444 267 157 18 233 418 79 244 36 31 29 453 178 82 131 2 483 86 149 339 135 313 16 401 55 60 163 66 289 370 298 243 130 324 182 101 165 461 414 201 492 151 330 421 374 373 46 30 409 137 12 65 104 395 394 204 352 481 95 146 169 68 1 372 397 400 411 11 93 214 224 64 282 3 489 127 17 193 455 367 407 216 100 366 184 273 405 284 134 108 250 351 450 10 144 363 303 58 388 97 47 154 443 160 45 471 51 0 248 61 477 196 331 404 475 304 103 369 132 40 353 162 344 90 142 294 71 445 180 136 466 185 431 220 299 133 143 457 389 272 207 375 408 70 499 391 365 249 478 226 262 209 485 479 228 343 231 52 77 129 484 326 229 297 460 211 173 88 290 123 239 105 451 168 128 274 258 237 470 245 4 387 230 57 318 464 292 474 145 152 206 148 115 458 56 238 63 69 42 261 376 218 316 110 199 288 117 325 53 124 442 80 419 301 276 37 380 197 379 172 377 215 120 495 198 497 121 27 13 293 181 346 125 360 44 24 270 314 427 159 490 217 358 9 333 354 281 241 20 116 139 222 476 232 296 54 176 422 23 19 118 98 278 92 25 72 300 254 327";
	t_split *split = ft_split(str1, ' ');
	t_split *split2 = ft_split(str2, ' ');
	char **splitted = split->str_arr;
	char **splitted2 = split2->str_arr;
	int counter = 1;
	while (0 == strcmp(splitted[counter], splitted2[counter]))
		counter++;
	printf("%s\n", splitted[counter]);
	printf("%d\n", counter);
}
