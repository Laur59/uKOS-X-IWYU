/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 *  Goal:   Demo of a C application.
 *          Simple UI for the debris demo.
 */

#include    "ui.h"

#include    <stdint.h>

#include    "database.h"
#include    "kern/kern.h"
#include    "kern/kern_types.h"
#include    "macros.h"
#include    "macros_soc.h"
#include    "random/random.h"
#include    "ulvgl.h"

extern  mutx_t          *vLVGL_API[KNB_CORES];
extern  lv_image_dsc_t  background;
extern  lv_image_dsc_t  debri_01;
        lv_obj_t        *vImage[KNB_CORES];
        lv_obj_t        *vArc[KNB_CORES];
        lv_obj_t        *vL_probability[KNB_CORES];
        lv_obj_t        *vL_class[KNB_CORES];
        lv_obj_t        *vL_Ex_TensorFlow[KNB_CORES];
        lv_obj_t        *vL_Ex_mlpn[KNB_CORES];
        lv_obj_t        *vL_Canvas[KNB_CORES];
static  uint8_t         vCanvasBuf[KNB_CORES][DST_W * DST_H * 4];

// Prototypes

static  void    local_PrepareDrawingText_Probability(void);
static  void    local_PrepareDrawingText_Class(void);
static  void    local_PrepareDrawingText_TensorFlow(void);
static  void    local_PrepareDrawingText_Mlpn(void);
static  void    local_PrepareDrawingBackground(void);
static  void    local_PrepareDrawingArc(void);
static  void    local_PrepareDrawingCanvas(void);
static  void    local_setAngle_cb(void *object, int32_t angle);

/*
 * \brief ui_draw
 *
 * - Draw all the widgets
 *
 */
void    ui_draw(void) {

    local_PrepareDrawingBackground();
    local_PrepareDrawingArc();
    local_PrepareDrawingText_Probability();
    local_PrepareDrawingText_Class();
    local_PrepareDrawingText_TensorFlow();
    local_PrepareDrawingText_Mlpn();
    local_PrepareDrawingCanvas();
}

/*
 * \brief ui_drawProbability
 *
 * - Draw the probability
 *
 */
void    ui_drawProbability(const char_t *s) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    lv_label_set_text(vL_probability[core], s);
    kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief ui_drawClass
 *
 * - Draw the class
 *
 */
void    ui_drawClass(const char_t *s) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    lv_label_set_text(vL_class[core], s);
    kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief ui_drawTensorFlowExecutionTime
 *
 * - Draw the TensorFlow execution time
 *
 */
void    ui_drawTensorFlowExecutionTime(const char_t *s) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    lv_label_set_text(vL_Ex_TensorFlow[core], s);
    kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief ui_drawMlpnExecutionTime
 *
 * - Draw the mlpn execution time
 *
 */
void    ui_drawMlpnExecutionTime(const char_t *s) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    lv_label_set_text(vL_Ex_mlpn[core], s);
    kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief ui_drawSmallImage
 *
 * - Process the smallImage (zoom)
 * - Apply an anti-aliasing
 * - Add some color noise
 *
 */
void ui_drawSmallImage(const dataBase_t *entry) {
            uint32_t                core, random[3], tint_r, tint_g, tint_b;
            int32_t                 x, y, r, g, b;
            lv_draw_image_dsc_t     dsc;
            lv_layer_t              layer;
            lv_color32_t            px;
            lv_area_t               coords = { 0, 0, (DST_W - 1), (DST_H - 1) };
    const   lv_image_dsc_t          *classImage;

    core = GET_RUNNING_CORE;

    classImage = entry->oClassImage;
    if (classImage == nullptr) { return; }

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    lv_canvas_fill_bg(vL_Canvas[core], lv_color_hex(KBLACK), LV_OPA_TRANSP);
    lv_canvas_init_layer(vL_Canvas[core], &layer);
    lv_draw_image_dsc_init(&dsc);
    dsc.src = classImage;

// Zoom the smallImage (from 80x80 to 120x120)
// 256 = 100%, 384 = 150%

    dsc.scale_x   = (256 * DST_W) / SRC_W;
    dsc.scale_y   = (256 * DST_H) / SRC_H;
    dsc.pivot.x   = 0;
    dsc.pivot.y   = 0;
    dsc.antialias = 1;

    lv_draw_image(&layer, &dsc, &coords);
    lv_canvas_finish_layer(vL_Canvas[core], &layer);

// Random color

    random_read(KRANDOM_SOFT, &random[0], 3U);
    tint_r = random[0] % 256U;
    tint_g = random[1] % 256U;
    tint_b = random[2] % 256U;

    lv_display_enable_invalidation(lv_obj_get_display(vL_Canvas[core]), false);

    for (y = 0; y < DST_H; y++) {
        for (x = 0; x < DST_W; x++) {
            px = lv_canvas_get_px(vL_Canvas[core], x, y);

            if (px.alpha == 0) {
                continue;
            }

// Mix the colors

            r = ((int32_t)px.red   + (int32_t)tint_r) / 2;
            g = ((int32_t)px.green + (int32_t)tint_g) / 2;
            b = ((int32_t)px.blue  + (int32_t)tint_b) / 2;

            if (r < 0) { r = 0; } if (r > 255) { r = 255; }
            if (g < 0) { g = 0; } if (g > 255) { g = 255; }
            if (b < 0) { b = 0; } if (b > 255) { b = 255; }

            lv_canvas_set_px(vL_Canvas[core], x, y, lv_color_make((uint8_t)r, (uint8_t)g, (uint8_t)b), px.alpha);
        }
    }
    lv_display_enable_invalidation(lv_obj_get_display(vL_Canvas[core]), true);
    lv_obj_invalidate(vL_Canvas[core]);
    kern_unlockMutex(vLVGL_API[core]);
}

// Local routines
// ==============

/*
 * \brief local_PrepareDrawingBackground
 *
 * - Prepare for drawing the background picture
 *
 */
static  void    local_PrepareDrawingBackground(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    vImage[core] = lv_image_create(lv_screen_active());
    lv_image_set_src(vImage[core], &background);
    lv_obj_align(vImage[core], LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_hidden(vImage[core], false);
    kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief local_PrepareDrawingArc
 *
 * - Prepare for drawing the arc circle (continuously)
 *
 */
static  void    local_PrepareDrawingArc(void) {
    uint32_t    core;
    lv_anim_t   animation;

    core = GET_RUNNING_CORE;

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    vArc[core] = lv_arc_create(lv_screen_active());
    lv_obj_set_size(vArc[core], KARC_DIAMETER, KARC_DIAMETER);
    lv_obj_set_style_arc_width(vArc[core], KARC_WIDTH, LV_PART_MAIN);
    lv_obj_set_style_arc_width(vArc[core], KARC_WIDTH, LV_PART_INDICATOR);

    lv_arc_set_rotation(vArc[core], 270U);
    lv_arc_set_bg_angles(vArc[core], 0U, 360U);
    lv_obj_remove_style(vArc[core], nullptr, LV_PART_KNOB);
    lv_obj_set_clickable(vArc[core], false);
    lv_obj_set_pos(vArc[core], KARC_POS_X, KARC_POS_Y);

    lv_anim_init(&animation);
    lv_anim_set_var(&animation, vArc[core]);
    lv_anim_set_exec_cb(&animation, local_setAngle_cb);
    lv_anim_set_duration(&animation, 1000U);
    lv_anim_set_repeat_count(&animation, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&animation, 500U);
    lv_anim_set_values(&animation, 0U, 100U);
    lv_anim_start(&animation);
    kern_unlockMutex(vLVGL_API[core]);
}

static  void    local_setAngle_cb(void *object, int32_t angle) {

    lv_arc_set_value((lv_obj_t *)object, angle);
}

/*
 * \brief local_PrepareDrawingText_Probability
 *
 * - Prepare for drawing the text, probability
 *
 */
static  void    local_PrepareDrawingText_Probability(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    vL_probability[core] = lv_label_create(lv_screen_active());
    lv_label_set_text(vL_probability[core], " ");
    lv_obj_set_style_text_color(vL_probability[core], lv_color_hex(KWHITE), 0);
    lv_obj_set_style_text_font(vL_probability[core], &lv_font_montserrat_16, 0);
    lv_obj_align(vL_probability[core], LV_ALIGN_TOP_LEFT, KTEXT_POS_X_1, KTEXT_POS_Y_1);
    kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief local_PrepareDrawingText_Class
 *
 * - Prepare for drawing the text, probability & class
 *
 */
static  void    local_PrepareDrawingText_Class(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    vL_class[core] = lv_label_create(lv_screen_active());
    lv_label_set_text(vL_class[core], " ");
    lv_obj_set_style_text_color(vL_class[core], lv_color_hex(KWHITE), 0);
    lv_obj_set_style_text_font(vL_class[core], &lv_font_montserrat_26, 0);
    lv_obj_align(vL_class[core], LV_ALIGN_TOP_LEFT, KTEXT_POS_X_2, KTEXT_POS_Y_2);
    kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief local_PrepareDrawingText_TensorFlow
 *
 * - Prepare for drawing the text execution time TensorFlow
 *
 */
static  void    local_PrepareDrawingText_TensorFlow(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    vL_Ex_TensorFlow[core] = lv_label_create(lv_screen_active());
    lv_label_set_text(vL_Ex_TensorFlow[core], " ");
    lv_obj_set_style_text_color(vL_Ex_TensorFlow[core], lv_color_hex(KWHITE), 0);
    lv_obj_set_style_text_font(vL_Ex_TensorFlow[core], &lv_font_montserrat_16, 0);
    lv_obj_align(vL_Ex_TensorFlow[core], LV_ALIGN_TOP_LEFT, KTEXT_POS_X_3, KTEXT_POS_Y_3);
    kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief local_PrepareDrawingText_Mlpn
 *
 * - Prepare for drawing the text execution time TensorFlow
 *
 */
static  void    local_PrepareDrawingText_Mlpn(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    vL_Ex_mlpn[core] = lv_label_create(lv_screen_active());
    lv_label_set_text(vL_Ex_mlpn[core], " ");
    lv_obj_set_style_text_color(vL_Ex_mlpn[core], lv_color_hex(KWHITE), 0);
    lv_obj_set_style_text_font(vL_Ex_mlpn[core], &lv_font_montserrat_16, 0);
    lv_obj_align(vL_Ex_mlpn[core], LV_ALIGN_TOP_LEFT, KTEXT_POS_X_4, KTEXT_POS_Y_4);
    kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief local_PrepareDrawingCanvas
 *
 * - Prepare for drawing the canvas
 *
 */
static void local_PrepareDrawingCanvas(void) {
    uint32_t core;

    core = GET_RUNNING_CORE;

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    vL_Canvas[core] = lv_canvas_create(lv_screen_active());
    lv_canvas_set_buffer(vL_Canvas[core], &vCanvasBuf[core][0], DST_W, DST_H, LV_COLOR_FORMAT_ARGB8888);
    lv_canvas_fill_bg(vL_Canvas[core], lv_color_hex(KBLACK), LV_OPA_TRANSP);
    lv_obj_set_pos(vL_Canvas[core], KIMAGE_POS_X, KIMAGE_POS_Y);
    kern_unlockMutex(vLVGL_API[core]);
}
