
enumb wd_type {
	wdt_abstract,
	wdt_assert,
	wdt_boolean,
	wdt_break,
	wdt_byte,
	wdt_case,
	wdt_catch,
	wdt_char,
	wdt_class,
	wdt_continue,
	wdt_default,
	wdt_do,
	wdt_double,
	wdt_else,
	wdt_enum,
	wdt_extends,
	wdt_final,
	wdt_finally,
	wdt_float,
	wdt_for,
	wdt_if,
	wdt_implements,
	wdt_import,
	wdt_instanceof,
	wdt_int,
	wdt_interface,
	wdt_long,
	wdt_native,
	wdt_new,
	wdt_package,
	wdt_private,
	wdt_protected,
	wdt_public,
	wdt_return,
	wdt_strictfp,
	wdt_short,
	wdt_static,
	wdt_super,
	wdt_switch,
	wdt_synchronized,
	wdt_this,
	wdt_throw,
	wdt_throws,
	wdt_transient,
	wdt_try,
	wdt_void,
	wdt_volatile,
	wdt_while,
	wdt_id,
};

struct wd_context;

struct word {
	int is_word:1;	// 1: word, 0: symbol
	int eof:1;	// end of file
	enum wd_type wdt; // word type if is_word
	char* data;	// content of wdt_id
};

struct wd_context* wdc_create(char *fn);
void wdc_free(struct wd_context *wdc);

struct word* wd_next(struct wd_context *wdc);
void wd_free(struct word *wd);
