#include <stdlib.h>

#include "../config.h"
#include "../config-verify.h"
#include "../decoration.h"
#include "../plugin.h"

struct private {
    struct rgba color;
};

static void
destroy(struct deco *deco)
{
    struct private *d = deco->private;
    free(d);
    free(deco);
}

static void
expose(const struct deco *deco, cairo_t *cr, int x, int y, int width, int height)
{
    const struct private *d = deco->private;
    cairo_set_source_rgba(
        cr, d->color.red, d->color.green, d->color.blue, d->color.alpha);
    cairo_rectangle(cr, x, y, width, height);
    cairo_fill(cr);
}

static struct deco *
background_new(struct rgba color)
{
    struct private *priv = malloc(sizeof(*priv));
    priv->color = color;

    struct deco *deco = malloc(sizeof(*deco));
    deco->private = priv;
    deco->expose = &expose;
    deco->destroy = &destroy;

    return deco;
}

static struct deco *
from_conf(const struct yml_node *node)
{
    const struct yml_node *color = yml_get_value(node, "color");
    return background_new(conf_to_color(color));
}

static bool
verify_conf(keychain_t *chain, const struct yml_node *node)
{
    static const struct attr_info attrs[] = {
        {"color", true, &conf_verify_color},
        DECORATION_COMMON_ATTRS,
    };

    return conf_verify_dict(chain, node, attrs);
}

const struct deco_iface deco_background_iface = {
    .verify_conf = &verify_conf,
    .from_conf = &from_conf,
};

#if defined(CORE_PLUGINS_AS_SHARED_LIBRARIES)
extern const struct deco_iface iface __attribute__((weak, alias("deco_background_iface")));
#endif
