/* See LICENSE file for copyright and license details. */


/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 29;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const unsigned int gappx     = 9;       /* gap pixel between windows */
static const char *fonts[]          = { "Hasklig-12.5:style=Regular", "Hasklig Medium-13.5:style=Medium,Regular" };
static const char dmenufont[]       = "Hasklug:size=12.5";
static const char col_gray1[]       = "#21252b";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#56b6c2";
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const int focusonwheel       = 0; 	/* focusonclick patch */
static const unsigned int baralpha = 0xd8;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_cyan, col_gray1,  col_cyan  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* launcher commands (They must be NULL terminated) */
static const char* firefox[]	= { "firefox", NULL };
static const char* code[]	= { "code-oss", NULL };
static const char* typora[]	= { "typora", NULL };
static const char* vm[]		= { "virtualbox", NULL };
static const char* spotify[]=     { "spotify", NULL };
static const char* pass[]	= { "keepassxc", NULL };

static const Launcher launchers[] = {
       /* command       name to display */
       { firefox,	"" },
       { code, 		"" },
       { spotify, 	"阮" },
       { pass, 		"" },
       { typora, 	"" },
       { vm, 		"" }, 

};

/* tagging */
static const char *tags[] = { "", "", "", ""};
static const char *active_tags[] = { "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class              instance    title       tags mask     isfloating   monitor */
	{ "discord",          NULL,       NULL,       1 << 3,       0,           0  },
	{ "telegram-desktop", NULL,       NULL,       1 << 3,       0,           0  },
	{ "vlc",              NULL,       NULL,       1 << 2,       0,           0  },
	{ "Spotify",          "spotify",  NULL,       1 << 2,       0,           0  }, // doesn't work, idk why
	{ NULL,               NULL,       NULL,       0,            0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.6; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run_i", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, "-shb", col_cyan, NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *fileexplorer[] = { "thunar", NULL };
static const char *screenshot[] = { "flameshot", "gui", NULL };
static const char *lockscreen[] = { "slock", NULL };


#define VOLUMESCRIPT "/home/david/Workspace/Projets/scripts-divers/volume/volume.sh"
static const char *upvol[]   = { VOLUMESCRIPT, "up",     NULL };
static const char *downvol[] = { VOLUMESCRIPT, "down",   NULL };
static const char *mutevol[] = { VOLUMESCRIPT, "toggle", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_q,	   spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,             		XK_e,	   spawn,          {.v = fileexplorer } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,	                XK_w,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_F1,     spawn,          {.v = firefox } },
	{ MODKEY,                       XK_F2,     spawn,          {.v = code } },
	{ MODKEY,                       XK_F3,     spawn,          {.v = spotify } },
	{ MODKEY,                       XK_F4,     spawn,          {.v = pass} },
	{ MODKEY,                       XK_F5,     spawn,          {.v = typora } },
	{ MODKEY,                       XK_F6,     spawn,          {.v = vm } },
	{ MODKEY,                       XK_F9,     spawn,          {.v = mutevol } },
	{ MODKEY,                       XK_F11,    spawn,          {.v = downvol } },
	{ MODKEY,                       XK_F12,    spawn,          {.v = upvol   } },
	{ MODKEY,                       XK_Print,  spawn,          {.v = screenshot } },
	{ MODKEY,                       XK_Escape, spawn,          {.v = lockscreen } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

