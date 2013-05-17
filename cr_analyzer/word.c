/*
 * Get words of java language
 */

static const char* keywords[] = {
	"abstract",
	"assert",
	"boolean",
	"break",
	"byte",
	"case",
	"catch",
	"char",
	"class",
	"continue",
	"default",
	"do",
	"double",
	"else",
	"enum",
	"extends",
	"final",
	"finally",
	"float",
	"for",
	"if",
	"implements",
	"import",
	"instanceof",
	"int",
	"interface",
	"long",
	"native",
	"new",
	"package",
	"private",
	"protected",
	"public",
	"return",
	"strictfp",
	"short",
	"static",
	"super",
	"switch",
	"synchronized",
	"this",
	"throw",
	"throws",
	"transient",
	"try",
	"void",
	"volatile",
	"while",
};

struct wd_context {
	int fd;
	char buf[4*1024];
	int idx;
	int len;
};

struct wd_context* wdc_create(char *fn)
{
	struct wd_context *wdc = malloc(sizeof(*wdc));

	wdc->fd = open(fn, O_RDONLY);
	if (wdc->fd < 0) {
		perror(fn);
		free(wdc);
		return NULL;
	}

	return wdc;
}

void wdc_free(struct wd_context *wdc)
{
	close(wdc->fd);
	free(wdc);
}

struct word* wd_next(struct wd_context *wdc)
{
	if (!wdc->len) {
		wdc->len = read(wdc->fd, wdc->buf, 4*1024);
	}

	char *wd_str;
	struct word *wd;

	wd_str = get_wd_str(struct wd_context *wdc);
	if (!wd)
		return wd;

	wd = malloc(*wd);
	str2wd(wd_str, wd);

	return wd;
}

void wd_free(struct word *wd)
{
	if (wd->data)
		free(wd->data);
	free(wd);
}
