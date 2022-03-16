/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sha256_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:04:46 by matheme           #+#    #+#             */
/*   Updated: 2022/03/15 21:51:29 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"

static int k(int id) {
    static const uint32_t k[] = {
0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };
    return (k[id]);
}

static void sha256_transform(t_sha256 *ctx, unsigned char data[64])
{
	unsigned int	i;
	unsigned int	t1;
	unsigned int	t2;
	unsigned int	m[64];
	t_sha256		tmp_ctx;

	i = -1;
	while (++i < 16)
		m[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) | (data[i * 4 + 2] << 8) | (data[i * 4 + 3]);
	i--;
	while (++i < 64)
		m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];

	ft_memcpy(&tmp_ctx.state, ctx->state, sizeof(tmp_ctx.state));
	i = -1;
	while (++i < 64) {
		t1 = tmp_ctx.state[7] + EP1(tmp_ctx.state[4]) + CH(tmp_ctx.state[4],tmp_ctx.state[5],tmp_ctx.state[6]) + k(i) + m[i];
		t2 = EP0(tmp_ctx.state[0]) + MAJ(tmp_ctx.state[0],tmp_ctx.state[1],	tmp_ctx.state[2]);
		tmp_ctx.state[7] = tmp_ctx.state[6];
		tmp_ctx.state[6] = tmp_ctx.state[5];
		tmp_ctx.state[5] = tmp_ctx.state[4];
		tmp_ctx.state[4] = tmp_ctx.state[3] + t1;
		tmp_ctx.state[3] = tmp_ctx.state[2];
		tmp_ctx.state[2] = tmp_ctx.state[1];
		tmp_ctx.state[1] = tmp_ctx.state[0];
		tmp_ctx.state[0] = t1 + t2;
	}
	ctx->state[0] += tmp_ctx.state[0];
	ctx->state[1] += tmp_ctx.state[1];
	ctx->state[2] += tmp_ctx.state[2];
	ctx->state[3] += tmp_ctx.state[3];
	ctx->state[4] += tmp_ctx.state[4];
	ctx->state[5] += tmp_ctx.state[5];
	ctx->state[6] += tmp_ctx.state[6];
	ctx->state[7] += tmp_ctx.state[7];
}



static void sha256_update(t_sha256 *ctx, const char *file, size_t data_len)
{
	int i;

	i = -1;
	while (++i < data_len)
	{
		ctx->data[ctx->datalen++] = file[i];
		if (ctx->datalen == 64) {
			sha256_transform(ctx, ctx->data);
			ctx->bitlen += 512;
			ctx->datalen = 0;
		}
	}
}

void sha256_final(t_sha256 *ctx, char *hash)
{
	int j;

	ctx->data[ctx->datalen] = 0x80;
	if (ctx->datalen < 56) {
		ft_bzero(&ctx->data[ctx->datalen + 1], 56 - ctx->datalen + 1);
	} else {
		ft_bzero(&ctx->data[ctx->datalen + 1], 64 - ctx->datalen + 1);
		sha256_transform(ctx, ctx->data);
		ft_bzero(ctx->data, 56);
	}
	ctx->bitlen += ctx->datalen * 8;
	ctx->data[63] = ctx->bitlen;
	ctx->data[62] = ctx->bitlen >> 8;
	ctx->data[61] = ctx->bitlen >> 16;
	ctx->data[60] = ctx->bitlen >> 24;
	ctx->data[59] = ctx->bitlen >> 32;
	ctx->data[58] = ctx->bitlen >> 40;
	ctx->data[57] = ctx->bitlen >> 48;
	ctx->data[56] = ctx->bitlen >> 56;
	sha256_transform(ctx, ctx->data);

	j = -1;
	while (++j < 4)
	{
		hash[j]      = (ctx->state[0] >> (24 - j * 8)) & 0xff;
		hash[j + 4]  = (ctx->state[1] >> (24 - j * 8)) & 0xff;
		hash[j + 8]  = (ctx->state[2] >> (24 - j * 8)) & 0xff;
		hash[j + 12] = (ctx->state[3] >> (24 - j * 8)) & 0xff;
		hash[j + 16] = (ctx->state[4] >> (24 - j * 8)) & 0xff;
		hash[j + 20] = (ctx->state[5] >> (24 - j * 8)) & 0xff;
		hash[j + 24] = (ctx->state[6] >> (24 - j * 8)) & 0xff;
		hash[j + 28] = (ctx->state[7] >> (24 - j * 8)) & 0xff;
	}
}


char *sha256_algo(int option, int file_len, char *file)
{
    t_sha256 ctx;
    char    *hash_in_dec;
	char	*hash;
	int		i;

	hash = NULL;
  	ft_bzero(&ctx, sizeof(ctx));
	ctx.state[0] = 0x6a09e667;
	ctx.state[1] = 0xbb67ae85;
	ctx.state[2] = 0x3c6ef372;
	ctx.state[3] = 0xa54ff53a;
	ctx.state[4] = 0x510e527f;
	ctx.state[5] = 0x9b05688c;
	ctx.state[6] = 0x1f83d9ab;
	ctx.state[7] = 0x5be0cd19;

    sha256_update(&ctx, file, file_len);
    if (!(hash_in_dec = ft_strnew(32)))
		return (NULL);
    sha256_final(&ctx, hash_in_dec);

	i = 0;
	hash = ft_utoa_base_champ(hash_in_dec[0], 16, 2);
	while (++i < 32)
		ft_strjoin_free(&hash, ft_utoa_base_champ(hash_in_dec[i], 16, 2));
    return (hash);
}



