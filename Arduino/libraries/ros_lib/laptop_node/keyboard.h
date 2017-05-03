#ifndef _ROS_laptop_node_keyboard_h
#define _ROS_laptop_node_keyboard_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace laptop_node
{

  class keyboard : public ros::Msg
  {
    public:
      typedef bool _k_up_type;
      _k_up_type k_up;
      typedef bool _k_down_type;
      _k_down_type k_down;
      typedef bool _k_right_type;
      _k_right_type k_right;
      typedef bool _k_left_type;
      _k_left_type k_left;
      typedef bool _k_backspace_type;
      _k_backspace_type k_backspace;
      typedef bool _k_tab_type;
      _k_tab_type k_tab;
      typedef bool _k_clear_type;
      _k_clear_type k_clear;
      typedef bool _k_return_type;
      _k_return_type k_return;
      typedef bool _k_pause_type;
      _k_pause_type k_pause;
      typedef bool _k_escape_type;
      _k_escape_type k_escape;
      typedef bool _k_space_type;
      _k_space_type k_space;
      typedef bool _k_insert_type;
      _k_insert_type k_insert;
      typedef bool _k_home_type;
      _k_home_type k_home;
      typedef bool _k_end_type;
      _k_end_type k_end;
      typedef bool _k_pageup_type;
      _k_pageup_type k_pageup;
      typedef bool _k_pagedown_type;
      _k_pagedown_type k_pagedown;
      typedef bool _k_numlock_type;
      _k_numlock_type k_numlock;
      typedef bool _k_capslock_type;
      _k_capslock_type k_capslock;
      typedef bool _k_scrollock_type;
      _k_scrollock_type k_scrollock;
      typedef bool _k_rshift_type;
      _k_rshift_type k_rshift;
      typedef bool _k_lshift_type;
      _k_lshift_type k_lshift;
      typedef bool _k_rctrl_type;
      _k_rctrl_type k_rctrl;
      typedef bool _k_lctrl_type;
      _k_lctrl_type k_lctrl;
      typedef bool _k_ralt_type;
      _k_ralt_type k_ralt;
      typedef bool _k_lalt_type;
      _k_lalt_type k_lalt;
      typedef bool _k_rmeta_type;
      _k_rmeta_type k_rmeta;
      typedef bool _k_lmeta_type;
      _k_lmeta_type k_lmeta;
      typedef bool _k_lsuper_type;
      _k_lsuper_type k_lsuper;
      typedef bool _k_rsuper_type;
      _k_rsuper_type k_rsuper;
      typedef bool _k_mode_type;
      _k_mode_type k_mode;
      typedef bool _k_help_type;
      _k_help_type k_help;
      typedef bool _k_print_type;
      _k_print_type k_print;
      typedef bool _k_sysreq_type;
      _k_sysreq_type k_sysreq;
      typedef bool _k_break_type;
      _k_break_type k_break;
      typedef bool _k_menu_type;
      _k_menu_type k_menu;
      typedef bool _k_power_type;
      _k_power_type k_power;
      typedef bool _k_euro_type;
      _k_euro_type k_euro;
      typedef bool _k_0_type;
      _k_0_type k_0;
      typedef bool _k_1_type;
      _k_1_type k_1;
      typedef bool _k_2_type;
      _k_2_type k_2;
      typedef bool _k_3_type;
      _k_3_type k_3;
      typedef bool _k_4_type;
      _k_4_type k_4;
      typedef bool _k_5_type;
      _k_5_type k_5;
      typedef bool _k_6_type;
      _k_6_type k_6;
      typedef bool _k_7_type;
      _k_7_type k_7;
      typedef bool _k_8_type;
      _k_8_type k_8;
      typedef bool _k_9_type;
      _k_9_type k_9;
      typedef bool _k_colon_type;
      _k_colon_type k_colon;
      typedef bool _k_semicolon_type;
      _k_semicolon_type k_semicolon;
      typedef bool _k_less_type;
      _k_less_type k_less;
      typedef bool _k_equals_type;
      _k_equals_type k_equals;
      typedef bool _k_greater_type;
      _k_greater_type k_greater;
      typedef bool _k_question_type;
      _k_question_type k_question;
      typedef bool _k_at_type;
      _k_at_type k_at;
      typedef bool _k_leftbracket_type;
      _k_leftbracket_type k_leftbracket;
      typedef bool _k_backslash_type;
      _k_backslash_type k_backslash;
      typedef bool _k_rightbracket_type;
      _k_rightbracket_type k_rightbracket;
      typedef bool _k_caret_type;
      _k_caret_type k_caret;
      typedef bool _k_underscore_type;
      _k_underscore_type k_underscore;
      typedef bool _k_backquote_type;
      _k_backquote_type k_backquote;
      typedef bool _k_exclaim_type;
      _k_exclaim_type k_exclaim;
      typedef bool _k_quotedbl_type;
      _k_quotedbl_type k_quotedbl;
      typedef bool _k_hash_type;
      _k_hash_type k_hash;
      typedef bool _k_dollar_type;
      _k_dollar_type k_dollar;
      typedef bool _k_ampersand_type;
      _k_ampersand_type k_ampersand;
      typedef bool _k_quote_type;
      _k_quote_type k_quote;
      typedef bool _k_leftparen_type;
      _k_leftparen_type k_leftparen;
      typedef bool _k_rightparen_type;
      _k_rightparen_type k_rightparen;
      typedef bool _k_asterisk_type;
      _k_asterisk_type k_asterisk;
      typedef bool _k_plus_type;
      _k_plus_type k_plus;
      typedef bool _k_comma_type;
      _k_comma_type k_comma;
      typedef bool _k_minus_type;
      _k_minus_type k_minus;
      typedef bool _k_period_type;
      _k_period_type k_period;
      typedef bool _k_slash_type;
      _k_slash_type k_slash;
      typedef bool _k_a_type;
      _k_a_type k_a;
      typedef bool _k_b_type;
      _k_b_type k_b;
      typedef bool _k_c_type;
      _k_c_type k_c;
      typedef bool _k_d_type;
      _k_d_type k_d;
      typedef bool _k_e_type;
      _k_e_type k_e;
      typedef bool _k_f_type;
      _k_f_type k_f;
      typedef bool _k_g_type;
      _k_g_type k_g;
      typedef bool _k_h_type;
      _k_h_type k_h;
      typedef bool _k_i_type;
      _k_i_type k_i;
      typedef bool _k_j_type;
      _k_j_type k_j;
      typedef bool _k_k_type;
      _k_k_type k_k;
      typedef bool _k_l_type;
      _k_l_type k_l;
      typedef bool _k_m_type;
      _k_m_type k_m;
      typedef bool _k_n_type;
      _k_n_type k_n;
      typedef bool _k_o_type;
      _k_o_type k_o;
      typedef bool _k_p_type;
      _k_p_type k_p;
      typedef bool _k_q_type;
      _k_q_type k_q;
      typedef bool _k_r_type;
      _k_r_type k_r;
      typedef bool _k_s_type;
      _k_s_type k_s;
      typedef bool _k_t_type;
      _k_t_type k_t;
      typedef bool _k_u_type;
      _k_u_type k_u;
      typedef bool _k_v_type;
      _k_v_type k_v;
      typedef bool _k_w_type;
      _k_w_type k_w;
      typedef bool _k_x_type;
      _k_x_type k_x;
      typedef bool _k_y_type;
      _k_y_type k_y;
      typedef bool _k_z_type;
      _k_z_type k_z;
      typedef bool _k_delete_type;
      _k_delete_type k_delete;
      typedef bool _k_kp0_type;
      _k_kp0_type k_kp0;
      typedef bool _k_kp1_type;
      _k_kp1_type k_kp1;
      typedef bool _k_kp2_type;
      _k_kp2_type k_kp2;
      typedef bool _k_kp3_type;
      _k_kp3_type k_kp3;
      typedef bool _k_kp4_type;
      _k_kp4_type k_kp4;
      typedef bool _k_kp5_type;
      _k_kp5_type k_kp5;
      typedef bool _k_kp6_type;
      _k_kp6_type k_kp6;
      typedef bool _k_kp7_type;
      _k_kp7_type k_kp7;
      typedef bool _k_kp8_type;
      _k_kp8_type k_kp8;
      typedef bool _k_kp9_type;
      _k_kp9_type k_kp9;
      typedef bool _k_kp_period_type;
      _k_kp_period_type k_kp_period;
      typedef bool _k_kp_divide_type;
      _k_kp_divide_type k_kp_divide;
      typedef bool _k_kp_multiply_type;
      _k_kp_multiply_type k_kp_multiply;
      typedef bool _k_kp_minus_type;
      _k_kp_minus_type k_kp_minus;
      typedef bool _k_kp_plus_type;
      _k_kp_plus_type k_kp_plus;
      typedef bool _k_kp_enter_type;
      _k_kp_enter_type k_kp_enter;
      typedef bool _k_kp_equals_type;
      _k_kp_equals_type k_kp_equals;
      typedef bool _k_f1_type;
      _k_f1_type k_f1;
      typedef bool _k_f2_type;
      _k_f2_type k_f2;
      typedef bool _k_f3_type;
      _k_f3_type k_f3;
      typedef bool _k_f4_type;
      _k_f4_type k_f4;
      typedef bool _k_f5_type;
      _k_f5_type k_f5;
      typedef bool _k_f6_type;
      _k_f6_type k_f6;
      typedef bool _k_f7_type;
      _k_f7_type k_f7;
      typedef bool _k_f8_type;
      _k_f8_type k_f8;
      typedef bool _k_f9_type;
      _k_f9_type k_f9;
      typedef bool _k_f10_type;
      _k_f10_type k_f10;
      typedef bool _k_f11_type;
      _k_f11_type k_f11;
      typedef bool _k_f12_type;
      _k_f12_type k_f12;
      typedef bool _k_f13_type;
      _k_f13_type k_f13;
      typedef bool _k_f14_type;
      _k_f14_type k_f14;
      typedef bool _k_f15_type;
      _k_f15_type k_f15;

    keyboard():
      k_up(0),
      k_down(0),
      k_right(0),
      k_left(0),
      k_backspace(0),
      k_tab(0),
      k_clear(0),
      k_return(0),
      k_pause(0),
      k_escape(0),
      k_space(0),
      k_insert(0),
      k_home(0),
      k_end(0),
      k_pageup(0),
      k_pagedown(0),
      k_numlock(0),
      k_capslock(0),
      k_scrollock(0),
      k_rshift(0),
      k_lshift(0),
      k_rctrl(0),
      k_lctrl(0),
      k_ralt(0),
      k_lalt(0),
      k_rmeta(0),
      k_lmeta(0),
      k_lsuper(0),
      k_rsuper(0),
      k_mode(0),
      k_help(0),
      k_print(0),
      k_sysreq(0),
      k_break(0),
      k_menu(0),
      k_power(0),
      k_euro(0),
      k_0(0),
      k_1(0),
      k_2(0),
      k_3(0),
      k_4(0),
      k_5(0),
      k_6(0),
      k_7(0),
      k_8(0),
      k_9(0),
      k_colon(0),
      k_semicolon(0),
      k_less(0),
      k_equals(0),
      k_greater(0),
      k_question(0),
      k_at(0),
      k_leftbracket(0),
      k_backslash(0),
      k_rightbracket(0),
      k_caret(0),
      k_underscore(0),
      k_backquote(0),
      k_exclaim(0),
      k_quotedbl(0),
      k_hash(0),
      k_dollar(0),
      k_ampersand(0),
      k_quote(0),
      k_leftparen(0),
      k_rightparen(0),
      k_asterisk(0),
      k_plus(0),
      k_comma(0),
      k_minus(0),
      k_period(0),
      k_slash(0),
      k_a(0),
      k_b(0),
      k_c(0),
      k_d(0),
      k_e(0),
      k_f(0),
      k_g(0),
      k_h(0),
      k_i(0),
      k_j(0),
      k_k(0),
      k_l(0),
      k_m(0),
      k_n(0),
      k_o(0),
      k_p(0),
      k_q(0),
      k_r(0),
      k_s(0),
      k_t(0),
      k_u(0),
      k_v(0),
      k_w(0),
      k_x(0),
      k_y(0),
      k_z(0),
      k_delete(0),
      k_kp0(0),
      k_kp1(0),
      k_kp2(0),
      k_kp3(0),
      k_kp4(0),
      k_kp5(0),
      k_kp6(0),
      k_kp7(0),
      k_kp8(0),
      k_kp9(0),
      k_kp_period(0),
      k_kp_divide(0),
      k_kp_multiply(0),
      k_kp_minus(0),
      k_kp_plus(0),
      k_kp_enter(0),
      k_kp_equals(0),
      k_f1(0),
      k_f2(0),
      k_f3(0),
      k_f4(0),
      k_f5(0),
      k_f6(0),
      k_f7(0),
      k_f8(0),
      k_f9(0),
      k_f10(0),
      k_f11(0),
      k_f12(0),
      k_f13(0),
      k_f14(0),
      k_f15(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_k_up;
      u_k_up.real = this->k_up;
      *(outbuffer + offset + 0) = (u_k_up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_up);
      union {
        bool real;
        uint8_t base;
      } u_k_down;
      u_k_down.real = this->k_down;
      *(outbuffer + offset + 0) = (u_k_down.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_down);
      union {
        bool real;
        uint8_t base;
      } u_k_right;
      u_k_right.real = this->k_right;
      *(outbuffer + offset + 0) = (u_k_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_right);
      union {
        bool real;
        uint8_t base;
      } u_k_left;
      u_k_left.real = this->k_left;
      *(outbuffer + offset + 0) = (u_k_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_left);
      union {
        bool real;
        uint8_t base;
      } u_k_backspace;
      u_k_backspace.real = this->k_backspace;
      *(outbuffer + offset + 0) = (u_k_backspace.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_backspace);
      union {
        bool real;
        uint8_t base;
      } u_k_tab;
      u_k_tab.real = this->k_tab;
      *(outbuffer + offset + 0) = (u_k_tab.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_tab);
      union {
        bool real;
        uint8_t base;
      } u_k_clear;
      u_k_clear.real = this->k_clear;
      *(outbuffer + offset + 0) = (u_k_clear.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_clear);
      union {
        bool real;
        uint8_t base;
      } u_k_return;
      u_k_return.real = this->k_return;
      *(outbuffer + offset + 0) = (u_k_return.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_return);
      union {
        bool real;
        uint8_t base;
      } u_k_pause;
      u_k_pause.real = this->k_pause;
      *(outbuffer + offset + 0) = (u_k_pause.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_pause);
      union {
        bool real;
        uint8_t base;
      } u_k_escape;
      u_k_escape.real = this->k_escape;
      *(outbuffer + offset + 0) = (u_k_escape.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_escape);
      union {
        bool real;
        uint8_t base;
      } u_k_space;
      u_k_space.real = this->k_space;
      *(outbuffer + offset + 0) = (u_k_space.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_space);
      union {
        bool real;
        uint8_t base;
      } u_k_insert;
      u_k_insert.real = this->k_insert;
      *(outbuffer + offset + 0) = (u_k_insert.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_insert);
      union {
        bool real;
        uint8_t base;
      } u_k_home;
      u_k_home.real = this->k_home;
      *(outbuffer + offset + 0) = (u_k_home.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_home);
      union {
        bool real;
        uint8_t base;
      } u_k_end;
      u_k_end.real = this->k_end;
      *(outbuffer + offset + 0) = (u_k_end.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_end);
      union {
        bool real;
        uint8_t base;
      } u_k_pageup;
      u_k_pageup.real = this->k_pageup;
      *(outbuffer + offset + 0) = (u_k_pageup.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_pageup);
      union {
        bool real;
        uint8_t base;
      } u_k_pagedown;
      u_k_pagedown.real = this->k_pagedown;
      *(outbuffer + offset + 0) = (u_k_pagedown.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_pagedown);
      union {
        bool real;
        uint8_t base;
      } u_k_numlock;
      u_k_numlock.real = this->k_numlock;
      *(outbuffer + offset + 0) = (u_k_numlock.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_numlock);
      union {
        bool real;
        uint8_t base;
      } u_k_capslock;
      u_k_capslock.real = this->k_capslock;
      *(outbuffer + offset + 0) = (u_k_capslock.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_capslock);
      union {
        bool real;
        uint8_t base;
      } u_k_scrollock;
      u_k_scrollock.real = this->k_scrollock;
      *(outbuffer + offset + 0) = (u_k_scrollock.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_scrollock);
      union {
        bool real;
        uint8_t base;
      } u_k_rshift;
      u_k_rshift.real = this->k_rshift;
      *(outbuffer + offset + 0) = (u_k_rshift.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_rshift);
      union {
        bool real;
        uint8_t base;
      } u_k_lshift;
      u_k_lshift.real = this->k_lshift;
      *(outbuffer + offset + 0) = (u_k_lshift.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_lshift);
      union {
        bool real;
        uint8_t base;
      } u_k_rctrl;
      u_k_rctrl.real = this->k_rctrl;
      *(outbuffer + offset + 0) = (u_k_rctrl.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_rctrl);
      union {
        bool real;
        uint8_t base;
      } u_k_lctrl;
      u_k_lctrl.real = this->k_lctrl;
      *(outbuffer + offset + 0) = (u_k_lctrl.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_lctrl);
      union {
        bool real;
        uint8_t base;
      } u_k_ralt;
      u_k_ralt.real = this->k_ralt;
      *(outbuffer + offset + 0) = (u_k_ralt.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_ralt);
      union {
        bool real;
        uint8_t base;
      } u_k_lalt;
      u_k_lalt.real = this->k_lalt;
      *(outbuffer + offset + 0) = (u_k_lalt.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_lalt);
      union {
        bool real;
        uint8_t base;
      } u_k_rmeta;
      u_k_rmeta.real = this->k_rmeta;
      *(outbuffer + offset + 0) = (u_k_rmeta.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_rmeta);
      union {
        bool real;
        uint8_t base;
      } u_k_lmeta;
      u_k_lmeta.real = this->k_lmeta;
      *(outbuffer + offset + 0) = (u_k_lmeta.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_lmeta);
      union {
        bool real;
        uint8_t base;
      } u_k_lsuper;
      u_k_lsuper.real = this->k_lsuper;
      *(outbuffer + offset + 0) = (u_k_lsuper.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_lsuper);
      union {
        bool real;
        uint8_t base;
      } u_k_rsuper;
      u_k_rsuper.real = this->k_rsuper;
      *(outbuffer + offset + 0) = (u_k_rsuper.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_rsuper);
      union {
        bool real;
        uint8_t base;
      } u_k_mode;
      u_k_mode.real = this->k_mode;
      *(outbuffer + offset + 0) = (u_k_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_mode);
      union {
        bool real;
        uint8_t base;
      } u_k_help;
      u_k_help.real = this->k_help;
      *(outbuffer + offset + 0) = (u_k_help.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_help);
      union {
        bool real;
        uint8_t base;
      } u_k_print;
      u_k_print.real = this->k_print;
      *(outbuffer + offset + 0) = (u_k_print.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_print);
      union {
        bool real;
        uint8_t base;
      } u_k_sysreq;
      u_k_sysreq.real = this->k_sysreq;
      *(outbuffer + offset + 0) = (u_k_sysreq.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_sysreq);
      union {
        bool real;
        uint8_t base;
      } u_k_break;
      u_k_break.real = this->k_break;
      *(outbuffer + offset + 0) = (u_k_break.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_break);
      union {
        bool real;
        uint8_t base;
      } u_k_menu;
      u_k_menu.real = this->k_menu;
      *(outbuffer + offset + 0) = (u_k_menu.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_menu);
      union {
        bool real;
        uint8_t base;
      } u_k_power;
      u_k_power.real = this->k_power;
      *(outbuffer + offset + 0) = (u_k_power.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_power);
      union {
        bool real;
        uint8_t base;
      } u_k_euro;
      u_k_euro.real = this->k_euro;
      *(outbuffer + offset + 0) = (u_k_euro.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_euro);
      union {
        bool real;
        uint8_t base;
      } u_k_0;
      u_k_0.real = this->k_0;
      *(outbuffer + offset + 0) = (u_k_0.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_0);
      union {
        bool real;
        uint8_t base;
      } u_k_1;
      u_k_1.real = this->k_1;
      *(outbuffer + offset + 0) = (u_k_1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_1);
      union {
        bool real;
        uint8_t base;
      } u_k_2;
      u_k_2.real = this->k_2;
      *(outbuffer + offset + 0) = (u_k_2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_2);
      union {
        bool real;
        uint8_t base;
      } u_k_3;
      u_k_3.real = this->k_3;
      *(outbuffer + offset + 0) = (u_k_3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_3);
      union {
        bool real;
        uint8_t base;
      } u_k_4;
      u_k_4.real = this->k_4;
      *(outbuffer + offset + 0) = (u_k_4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_4);
      union {
        bool real;
        uint8_t base;
      } u_k_5;
      u_k_5.real = this->k_5;
      *(outbuffer + offset + 0) = (u_k_5.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_5);
      union {
        bool real;
        uint8_t base;
      } u_k_6;
      u_k_6.real = this->k_6;
      *(outbuffer + offset + 0) = (u_k_6.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_6);
      union {
        bool real;
        uint8_t base;
      } u_k_7;
      u_k_7.real = this->k_7;
      *(outbuffer + offset + 0) = (u_k_7.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_7);
      union {
        bool real;
        uint8_t base;
      } u_k_8;
      u_k_8.real = this->k_8;
      *(outbuffer + offset + 0) = (u_k_8.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_8);
      union {
        bool real;
        uint8_t base;
      } u_k_9;
      u_k_9.real = this->k_9;
      *(outbuffer + offset + 0) = (u_k_9.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_9);
      union {
        bool real;
        uint8_t base;
      } u_k_colon;
      u_k_colon.real = this->k_colon;
      *(outbuffer + offset + 0) = (u_k_colon.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_colon);
      union {
        bool real;
        uint8_t base;
      } u_k_semicolon;
      u_k_semicolon.real = this->k_semicolon;
      *(outbuffer + offset + 0) = (u_k_semicolon.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_semicolon);
      union {
        bool real;
        uint8_t base;
      } u_k_less;
      u_k_less.real = this->k_less;
      *(outbuffer + offset + 0) = (u_k_less.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_less);
      union {
        bool real;
        uint8_t base;
      } u_k_equals;
      u_k_equals.real = this->k_equals;
      *(outbuffer + offset + 0) = (u_k_equals.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_equals);
      union {
        bool real;
        uint8_t base;
      } u_k_greater;
      u_k_greater.real = this->k_greater;
      *(outbuffer + offset + 0) = (u_k_greater.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_greater);
      union {
        bool real;
        uint8_t base;
      } u_k_question;
      u_k_question.real = this->k_question;
      *(outbuffer + offset + 0) = (u_k_question.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_question);
      union {
        bool real;
        uint8_t base;
      } u_k_at;
      u_k_at.real = this->k_at;
      *(outbuffer + offset + 0) = (u_k_at.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_at);
      union {
        bool real;
        uint8_t base;
      } u_k_leftbracket;
      u_k_leftbracket.real = this->k_leftbracket;
      *(outbuffer + offset + 0) = (u_k_leftbracket.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_leftbracket);
      union {
        bool real;
        uint8_t base;
      } u_k_backslash;
      u_k_backslash.real = this->k_backslash;
      *(outbuffer + offset + 0) = (u_k_backslash.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_backslash);
      union {
        bool real;
        uint8_t base;
      } u_k_rightbracket;
      u_k_rightbracket.real = this->k_rightbracket;
      *(outbuffer + offset + 0) = (u_k_rightbracket.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_rightbracket);
      union {
        bool real;
        uint8_t base;
      } u_k_caret;
      u_k_caret.real = this->k_caret;
      *(outbuffer + offset + 0) = (u_k_caret.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_caret);
      union {
        bool real;
        uint8_t base;
      } u_k_underscore;
      u_k_underscore.real = this->k_underscore;
      *(outbuffer + offset + 0) = (u_k_underscore.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_underscore);
      union {
        bool real;
        uint8_t base;
      } u_k_backquote;
      u_k_backquote.real = this->k_backquote;
      *(outbuffer + offset + 0) = (u_k_backquote.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_backquote);
      union {
        bool real;
        uint8_t base;
      } u_k_exclaim;
      u_k_exclaim.real = this->k_exclaim;
      *(outbuffer + offset + 0) = (u_k_exclaim.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_exclaim);
      union {
        bool real;
        uint8_t base;
      } u_k_quotedbl;
      u_k_quotedbl.real = this->k_quotedbl;
      *(outbuffer + offset + 0) = (u_k_quotedbl.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_quotedbl);
      union {
        bool real;
        uint8_t base;
      } u_k_hash;
      u_k_hash.real = this->k_hash;
      *(outbuffer + offset + 0) = (u_k_hash.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_hash);
      union {
        bool real;
        uint8_t base;
      } u_k_dollar;
      u_k_dollar.real = this->k_dollar;
      *(outbuffer + offset + 0) = (u_k_dollar.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_dollar);
      union {
        bool real;
        uint8_t base;
      } u_k_ampersand;
      u_k_ampersand.real = this->k_ampersand;
      *(outbuffer + offset + 0) = (u_k_ampersand.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_ampersand);
      union {
        bool real;
        uint8_t base;
      } u_k_quote;
      u_k_quote.real = this->k_quote;
      *(outbuffer + offset + 0) = (u_k_quote.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_quote);
      union {
        bool real;
        uint8_t base;
      } u_k_leftparen;
      u_k_leftparen.real = this->k_leftparen;
      *(outbuffer + offset + 0) = (u_k_leftparen.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_leftparen);
      union {
        bool real;
        uint8_t base;
      } u_k_rightparen;
      u_k_rightparen.real = this->k_rightparen;
      *(outbuffer + offset + 0) = (u_k_rightparen.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_rightparen);
      union {
        bool real;
        uint8_t base;
      } u_k_asterisk;
      u_k_asterisk.real = this->k_asterisk;
      *(outbuffer + offset + 0) = (u_k_asterisk.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_asterisk);
      union {
        bool real;
        uint8_t base;
      } u_k_plus;
      u_k_plus.real = this->k_plus;
      *(outbuffer + offset + 0) = (u_k_plus.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_plus);
      union {
        bool real;
        uint8_t base;
      } u_k_comma;
      u_k_comma.real = this->k_comma;
      *(outbuffer + offset + 0) = (u_k_comma.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_comma);
      union {
        bool real;
        uint8_t base;
      } u_k_minus;
      u_k_minus.real = this->k_minus;
      *(outbuffer + offset + 0) = (u_k_minus.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_minus);
      union {
        bool real;
        uint8_t base;
      } u_k_period;
      u_k_period.real = this->k_period;
      *(outbuffer + offset + 0) = (u_k_period.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_period);
      union {
        bool real;
        uint8_t base;
      } u_k_slash;
      u_k_slash.real = this->k_slash;
      *(outbuffer + offset + 0) = (u_k_slash.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_slash);
      union {
        bool real;
        uint8_t base;
      } u_k_a;
      u_k_a.real = this->k_a;
      *(outbuffer + offset + 0) = (u_k_a.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_a);
      union {
        bool real;
        uint8_t base;
      } u_k_b;
      u_k_b.real = this->k_b;
      *(outbuffer + offset + 0) = (u_k_b.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_b);
      union {
        bool real;
        uint8_t base;
      } u_k_c;
      u_k_c.real = this->k_c;
      *(outbuffer + offset + 0) = (u_k_c.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_c);
      union {
        bool real;
        uint8_t base;
      } u_k_d;
      u_k_d.real = this->k_d;
      *(outbuffer + offset + 0) = (u_k_d.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_d);
      union {
        bool real;
        uint8_t base;
      } u_k_e;
      u_k_e.real = this->k_e;
      *(outbuffer + offset + 0) = (u_k_e.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_e);
      union {
        bool real;
        uint8_t base;
      } u_k_f;
      u_k_f.real = this->k_f;
      *(outbuffer + offset + 0) = (u_k_f.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f);
      union {
        bool real;
        uint8_t base;
      } u_k_g;
      u_k_g.real = this->k_g;
      *(outbuffer + offset + 0) = (u_k_g.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_g);
      union {
        bool real;
        uint8_t base;
      } u_k_h;
      u_k_h.real = this->k_h;
      *(outbuffer + offset + 0) = (u_k_h.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_h);
      union {
        bool real;
        uint8_t base;
      } u_k_i;
      u_k_i.real = this->k_i;
      *(outbuffer + offset + 0) = (u_k_i.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_i);
      union {
        bool real;
        uint8_t base;
      } u_k_j;
      u_k_j.real = this->k_j;
      *(outbuffer + offset + 0) = (u_k_j.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_j);
      union {
        bool real;
        uint8_t base;
      } u_k_k;
      u_k_k.real = this->k_k;
      *(outbuffer + offset + 0) = (u_k_k.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_k);
      union {
        bool real;
        uint8_t base;
      } u_k_l;
      u_k_l.real = this->k_l;
      *(outbuffer + offset + 0) = (u_k_l.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_l);
      union {
        bool real;
        uint8_t base;
      } u_k_m;
      u_k_m.real = this->k_m;
      *(outbuffer + offset + 0) = (u_k_m.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_m);
      union {
        bool real;
        uint8_t base;
      } u_k_n;
      u_k_n.real = this->k_n;
      *(outbuffer + offset + 0) = (u_k_n.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_n);
      union {
        bool real;
        uint8_t base;
      } u_k_o;
      u_k_o.real = this->k_o;
      *(outbuffer + offset + 0) = (u_k_o.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_o);
      union {
        bool real;
        uint8_t base;
      } u_k_p;
      u_k_p.real = this->k_p;
      *(outbuffer + offset + 0) = (u_k_p.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_p);
      union {
        bool real;
        uint8_t base;
      } u_k_q;
      u_k_q.real = this->k_q;
      *(outbuffer + offset + 0) = (u_k_q.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_q);
      union {
        bool real;
        uint8_t base;
      } u_k_r;
      u_k_r.real = this->k_r;
      *(outbuffer + offset + 0) = (u_k_r.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_r);
      union {
        bool real;
        uint8_t base;
      } u_k_s;
      u_k_s.real = this->k_s;
      *(outbuffer + offset + 0) = (u_k_s.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_s);
      union {
        bool real;
        uint8_t base;
      } u_k_t;
      u_k_t.real = this->k_t;
      *(outbuffer + offset + 0) = (u_k_t.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_t);
      union {
        bool real;
        uint8_t base;
      } u_k_u;
      u_k_u.real = this->k_u;
      *(outbuffer + offset + 0) = (u_k_u.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_u);
      union {
        bool real;
        uint8_t base;
      } u_k_v;
      u_k_v.real = this->k_v;
      *(outbuffer + offset + 0) = (u_k_v.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_v);
      union {
        bool real;
        uint8_t base;
      } u_k_w;
      u_k_w.real = this->k_w;
      *(outbuffer + offset + 0) = (u_k_w.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_w);
      union {
        bool real;
        uint8_t base;
      } u_k_x;
      u_k_x.real = this->k_x;
      *(outbuffer + offset + 0) = (u_k_x.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_x);
      union {
        bool real;
        uint8_t base;
      } u_k_y;
      u_k_y.real = this->k_y;
      *(outbuffer + offset + 0) = (u_k_y.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_y);
      union {
        bool real;
        uint8_t base;
      } u_k_z;
      u_k_z.real = this->k_z;
      *(outbuffer + offset + 0) = (u_k_z.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_z);
      union {
        bool real;
        uint8_t base;
      } u_k_delete;
      u_k_delete.real = this->k_delete;
      *(outbuffer + offset + 0) = (u_k_delete.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_delete);
      union {
        bool real;
        uint8_t base;
      } u_k_kp0;
      u_k_kp0.real = this->k_kp0;
      *(outbuffer + offset + 0) = (u_k_kp0.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp0);
      union {
        bool real;
        uint8_t base;
      } u_k_kp1;
      u_k_kp1.real = this->k_kp1;
      *(outbuffer + offset + 0) = (u_k_kp1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp1);
      union {
        bool real;
        uint8_t base;
      } u_k_kp2;
      u_k_kp2.real = this->k_kp2;
      *(outbuffer + offset + 0) = (u_k_kp2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp2);
      union {
        bool real;
        uint8_t base;
      } u_k_kp3;
      u_k_kp3.real = this->k_kp3;
      *(outbuffer + offset + 0) = (u_k_kp3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp3);
      union {
        bool real;
        uint8_t base;
      } u_k_kp4;
      u_k_kp4.real = this->k_kp4;
      *(outbuffer + offset + 0) = (u_k_kp4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp4);
      union {
        bool real;
        uint8_t base;
      } u_k_kp5;
      u_k_kp5.real = this->k_kp5;
      *(outbuffer + offset + 0) = (u_k_kp5.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp5);
      union {
        bool real;
        uint8_t base;
      } u_k_kp6;
      u_k_kp6.real = this->k_kp6;
      *(outbuffer + offset + 0) = (u_k_kp6.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp6);
      union {
        bool real;
        uint8_t base;
      } u_k_kp7;
      u_k_kp7.real = this->k_kp7;
      *(outbuffer + offset + 0) = (u_k_kp7.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp7);
      union {
        bool real;
        uint8_t base;
      } u_k_kp8;
      u_k_kp8.real = this->k_kp8;
      *(outbuffer + offset + 0) = (u_k_kp8.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp8);
      union {
        bool real;
        uint8_t base;
      } u_k_kp9;
      u_k_kp9.real = this->k_kp9;
      *(outbuffer + offset + 0) = (u_k_kp9.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp9);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_period;
      u_k_kp_period.real = this->k_kp_period;
      *(outbuffer + offset + 0) = (u_k_kp_period.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp_period);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_divide;
      u_k_kp_divide.real = this->k_kp_divide;
      *(outbuffer + offset + 0) = (u_k_kp_divide.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp_divide);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_multiply;
      u_k_kp_multiply.real = this->k_kp_multiply;
      *(outbuffer + offset + 0) = (u_k_kp_multiply.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp_multiply);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_minus;
      u_k_kp_minus.real = this->k_kp_minus;
      *(outbuffer + offset + 0) = (u_k_kp_minus.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp_minus);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_plus;
      u_k_kp_plus.real = this->k_kp_plus;
      *(outbuffer + offset + 0) = (u_k_kp_plus.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp_plus);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_enter;
      u_k_kp_enter.real = this->k_kp_enter;
      *(outbuffer + offset + 0) = (u_k_kp_enter.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp_enter);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_equals;
      u_k_kp_equals.real = this->k_kp_equals;
      *(outbuffer + offset + 0) = (u_k_kp_equals.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_kp_equals);
      union {
        bool real;
        uint8_t base;
      } u_k_f1;
      u_k_f1.real = this->k_f1;
      *(outbuffer + offset + 0) = (u_k_f1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f1);
      union {
        bool real;
        uint8_t base;
      } u_k_f2;
      u_k_f2.real = this->k_f2;
      *(outbuffer + offset + 0) = (u_k_f2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f2);
      union {
        bool real;
        uint8_t base;
      } u_k_f3;
      u_k_f3.real = this->k_f3;
      *(outbuffer + offset + 0) = (u_k_f3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f3);
      union {
        bool real;
        uint8_t base;
      } u_k_f4;
      u_k_f4.real = this->k_f4;
      *(outbuffer + offset + 0) = (u_k_f4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f4);
      union {
        bool real;
        uint8_t base;
      } u_k_f5;
      u_k_f5.real = this->k_f5;
      *(outbuffer + offset + 0) = (u_k_f5.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f5);
      union {
        bool real;
        uint8_t base;
      } u_k_f6;
      u_k_f6.real = this->k_f6;
      *(outbuffer + offset + 0) = (u_k_f6.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f6);
      union {
        bool real;
        uint8_t base;
      } u_k_f7;
      u_k_f7.real = this->k_f7;
      *(outbuffer + offset + 0) = (u_k_f7.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f7);
      union {
        bool real;
        uint8_t base;
      } u_k_f8;
      u_k_f8.real = this->k_f8;
      *(outbuffer + offset + 0) = (u_k_f8.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f8);
      union {
        bool real;
        uint8_t base;
      } u_k_f9;
      u_k_f9.real = this->k_f9;
      *(outbuffer + offset + 0) = (u_k_f9.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f9);
      union {
        bool real;
        uint8_t base;
      } u_k_f10;
      u_k_f10.real = this->k_f10;
      *(outbuffer + offset + 0) = (u_k_f10.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f10);
      union {
        bool real;
        uint8_t base;
      } u_k_f11;
      u_k_f11.real = this->k_f11;
      *(outbuffer + offset + 0) = (u_k_f11.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f11);
      union {
        bool real;
        uint8_t base;
      } u_k_f12;
      u_k_f12.real = this->k_f12;
      *(outbuffer + offset + 0) = (u_k_f12.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f12);
      union {
        bool real;
        uint8_t base;
      } u_k_f13;
      u_k_f13.real = this->k_f13;
      *(outbuffer + offset + 0) = (u_k_f13.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f13);
      union {
        bool real;
        uint8_t base;
      } u_k_f14;
      u_k_f14.real = this->k_f14;
      *(outbuffer + offset + 0) = (u_k_f14.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f14);
      union {
        bool real;
        uint8_t base;
      } u_k_f15;
      u_k_f15.real = this->k_f15;
      *(outbuffer + offset + 0) = (u_k_f15.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->k_f15);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_k_up;
      u_k_up.base = 0;
      u_k_up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_up = u_k_up.real;
      offset += sizeof(this->k_up);
      union {
        bool real;
        uint8_t base;
      } u_k_down;
      u_k_down.base = 0;
      u_k_down.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_down = u_k_down.real;
      offset += sizeof(this->k_down);
      union {
        bool real;
        uint8_t base;
      } u_k_right;
      u_k_right.base = 0;
      u_k_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_right = u_k_right.real;
      offset += sizeof(this->k_right);
      union {
        bool real;
        uint8_t base;
      } u_k_left;
      u_k_left.base = 0;
      u_k_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_left = u_k_left.real;
      offset += sizeof(this->k_left);
      union {
        bool real;
        uint8_t base;
      } u_k_backspace;
      u_k_backspace.base = 0;
      u_k_backspace.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_backspace = u_k_backspace.real;
      offset += sizeof(this->k_backspace);
      union {
        bool real;
        uint8_t base;
      } u_k_tab;
      u_k_tab.base = 0;
      u_k_tab.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_tab = u_k_tab.real;
      offset += sizeof(this->k_tab);
      union {
        bool real;
        uint8_t base;
      } u_k_clear;
      u_k_clear.base = 0;
      u_k_clear.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_clear = u_k_clear.real;
      offset += sizeof(this->k_clear);
      union {
        bool real;
        uint8_t base;
      } u_k_return;
      u_k_return.base = 0;
      u_k_return.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_return = u_k_return.real;
      offset += sizeof(this->k_return);
      union {
        bool real;
        uint8_t base;
      } u_k_pause;
      u_k_pause.base = 0;
      u_k_pause.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_pause = u_k_pause.real;
      offset += sizeof(this->k_pause);
      union {
        bool real;
        uint8_t base;
      } u_k_escape;
      u_k_escape.base = 0;
      u_k_escape.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_escape = u_k_escape.real;
      offset += sizeof(this->k_escape);
      union {
        bool real;
        uint8_t base;
      } u_k_space;
      u_k_space.base = 0;
      u_k_space.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_space = u_k_space.real;
      offset += sizeof(this->k_space);
      union {
        bool real;
        uint8_t base;
      } u_k_insert;
      u_k_insert.base = 0;
      u_k_insert.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_insert = u_k_insert.real;
      offset += sizeof(this->k_insert);
      union {
        bool real;
        uint8_t base;
      } u_k_home;
      u_k_home.base = 0;
      u_k_home.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_home = u_k_home.real;
      offset += sizeof(this->k_home);
      union {
        bool real;
        uint8_t base;
      } u_k_end;
      u_k_end.base = 0;
      u_k_end.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_end = u_k_end.real;
      offset += sizeof(this->k_end);
      union {
        bool real;
        uint8_t base;
      } u_k_pageup;
      u_k_pageup.base = 0;
      u_k_pageup.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_pageup = u_k_pageup.real;
      offset += sizeof(this->k_pageup);
      union {
        bool real;
        uint8_t base;
      } u_k_pagedown;
      u_k_pagedown.base = 0;
      u_k_pagedown.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_pagedown = u_k_pagedown.real;
      offset += sizeof(this->k_pagedown);
      union {
        bool real;
        uint8_t base;
      } u_k_numlock;
      u_k_numlock.base = 0;
      u_k_numlock.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_numlock = u_k_numlock.real;
      offset += sizeof(this->k_numlock);
      union {
        bool real;
        uint8_t base;
      } u_k_capslock;
      u_k_capslock.base = 0;
      u_k_capslock.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_capslock = u_k_capslock.real;
      offset += sizeof(this->k_capslock);
      union {
        bool real;
        uint8_t base;
      } u_k_scrollock;
      u_k_scrollock.base = 0;
      u_k_scrollock.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_scrollock = u_k_scrollock.real;
      offset += sizeof(this->k_scrollock);
      union {
        bool real;
        uint8_t base;
      } u_k_rshift;
      u_k_rshift.base = 0;
      u_k_rshift.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_rshift = u_k_rshift.real;
      offset += sizeof(this->k_rshift);
      union {
        bool real;
        uint8_t base;
      } u_k_lshift;
      u_k_lshift.base = 0;
      u_k_lshift.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_lshift = u_k_lshift.real;
      offset += sizeof(this->k_lshift);
      union {
        bool real;
        uint8_t base;
      } u_k_rctrl;
      u_k_rctrl.base = 0;
      u_k_rctrl.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_rctrl = u_k_rctrl.real;
      offset += sizeof(this->k_rctrl);
      union {
        bool real;
        uint8_t base;
      } u_k_lctrl;
      u_k_lctrl.base = 0;
      u_k_lctrl.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_lctrl = u_k_lctrl.real;
      offset += sizeof(this->k_lctrl);
      union {
        bool real;
        uint8_t base;
      } u_k_ralt;
      u_k_ralt.base = 0;
      u_k_ralt.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_ralt = u_k_ralt.real;
      offset += sizeof(this->k_ralt);
      union {
        bool real;
        uint8_t base;
      } u_k_lalt;
      u_k_lalt.base = 0;
      u_k_lalt.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_lalt = u_k_lalt.real;
      offset += sizeof(this->k_lalt);
      union {
        bool real;
        uint8_t base;
      } u_k_rmeta;
      u_k_rmeta.base = 0;
      u_k_rmeta.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_rmeta = u_k_rmeta.real;
      offset += sizeof(this->k_rmeta);
      union {
        bool real;
        uint8_t base;
      } u_k_lmeta;
      u_k_lmeta.base = 0;
      u_k_lmeta.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_lmeta = u_k_lmeta.real;
      offset += sizeof(this->k_lmeta);
      union {
        bool real;
        uint8_t base;
      } u_k_lsuper;
      u_k_lsuper.base = 0;
      u_k_lsuper.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_lsuper = u_k_lsuper.real;
      offset += sizeof(this->k_lsuper);
      union {
        bool real;
        uint8_t base;
      } u_k_rsuper;
      u_k_rsuper.base = 0;
      u_k_rsuper.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_rsuper = u_k_rsuper.real;
      offset += sizeof(this->k_rsuper);
      union {
        bool real;
        uint8_t base;
      } u_k_mode;
      u_k_mode.base = 0;
      u_k_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_mode = u_k_mode.real;
      offset += sizeof(this->k_mode);
      union {
        bool real;
        uint8_t base;
      } u_k_help;
      u_k_help.base = 0;
      u_k_help.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_help = u_k_help.real;
      offset += sizeof(this->k_help);
      union {
        bool real;
        uint8_t base;
      } u_k_print;
      u_k_print.base = 0;
      u_k_print.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_print = u_k_print.real;
      offset += sizeof(this->k_print);
      union {
        bool real;
        uint8_t base;
      } u_k_sysreq;
      u_k_sysreq.base = 0;
      u_k_sysreq.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_sysreq = u_k_sysreq.real;
      offset += sizeof(this->k_sysreq);
      union {
        bool real;
        uint8_t base;
      } u_k_break;
      u_k_break.base = 0;
      u_k_break.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_break = u_k_break.real;
      offset += sizeof(this->k_break);
      union {
        bool real;
        uint8_t base;
      } u_k_menu;
      u_k_menu.base = 0;
      u_k_menu.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_menu = u_k_menu.real;
      offset += sizeof(this->k_menu);
      union {
        bool real;
        uint8_t base;
      } u_k_power;
      u_k_power.base = 0;
      u_k_power.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_power = u_k_power.real;
      offset += sizeof(this->k_power);
      union {
        bool real;
        uint8_t base;
      } u_k_euro;
      u_k_euro.base = 0;
      u_k_euro.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_euro = u_k_euro.real;
      offset += sizeof(this->k_euro);
      union {
        bool real;
        uint8_t base;
      } u_k_0;
      u_k_0.base = 0;
      u_k_0.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_0 = u_k_0.real;
      offset += sizeof(this->k_0);
      union {
        bool real;
        uint8_t base;
      } u_k_1;
      u_k_1.base = 0;
      u_k_1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_1 = u_k_1.real;
      offset += sizeof(this->k_1);
      union {
        bool real;
        uint8_t base;
      } u_k_2;
      u_k_2.base = 0;
      u_k_2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_2 = u_k_2.real;
      offset += sizeof(this->k_2);
      union {
        bool real;
        uint8_t base;
      } u_k_3;
      u_k_3.base = 0;
      u_k_3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_3 = u_k_3.real;
      offset += sizeof(this->k_3);
      union {
        bool real;
        uint8_t base;
      } u_k_4;
      u_k_4.base = 0;
      u_k_4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_4 = u_k_4.real;
      offset += sizeof(this->k_4);
      union {
        bool real;
        uint8_t base;
      } u_k_5;
      u_k_5.base = 0;
      u_k_5.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_5 = u_k_5.real;
      offset += sizeof(this->k_5);
      union {
        bool real;
        uint8_t base;
      } u_k_6;
      u_k_6.base = 0;
      u_k_6.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_6 = u_k_6.real;
      offset += sizeof(this->k_6);
      union {
        bool real;
        uint8_t base;
      } u_k_7;
      u_k_7.base = 0;
      u_k_7.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_7 = u_k_7.real;
      offset += sizeof(this->k_7);
      union {
        bool real;
        uint8_t base;
      } u_k_8;
      u_k_8.base = 0;
      u_k_8.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_8 = u_k_8.real;
      offset += sizeof(this->k_8);
      union {
        bool real;
        uint8_t base;
      } u_k_9;
      u_k_9.base = 0;
      u_k_9.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_9 = u_k_9.real;
      offset += sizeof(this->k_9);
      union {
        bool real;
        uint8_t base;
      } u_k_colon;
      u_k_colon.base = 0;
      u_k_colon.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_colon = u_k_colon.real;
      offset += sizeof(this->k_colon);
      union {
        bool real;
        uint8_t base;
      } u_k_semicolon;
      u_k_semicolon.base = 0;
      u_k_semicolon.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_semicolon = u_k_semicolon.real;
      offset += sizeof(this->k_semicolon);
      union {
        bool real;
        uint8_t base;
      } u_k_less;
      u_k_less.base = 0;
      u_k_less.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_less = u_k_less.real;
      offset += sizeof(this->k_less);
      union {
        bool real;
        uint8_t base;
      } u_k_equals;
      u_k_equals.base = 0;
      u_k_equals.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_equals = u_k_equals.real;
      offset += sizeof(this->k_equals);
      union {
        bool real;
        uint8_t base;
      } u_k_greater;
      u_k_greater.base = 0;
      u_k_greater.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_greater = u_k_greater.real;
      offset += sizeof(this->k_greater);
      union {
        bool real;
        uint8_t base;
      } u_k_question;
      u_k_question.base = 0;
      u_k_question.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_question = u_k_question.real;
      offset += sizeof(this->k_question);
      union {
        bool real;
        uint8_t base;
      } u_k_at;
      u_k_at.base = 0;
      u_k_at.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_at = u_k_at.real;
      offset += sizeof(this->k_at);
      union {
        bool real;
        uint8_t base;
      } u_k_leftbracket;
      u_k_leftbracket.base = 0;
      u_k_leftbracket.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_leftbracket = u_k_leftbracket.real;
      offset += sizeof(this->k_leftbracket);
      union {
        bool real;
        uint8_t base;
      } u_k_backslash;
      u_k_backslash.base = 0;
      u_k_backslash.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_backslash = u_k_backslash.real;
      offset += sizeof(this->k_backslash);
      union {
        bool real;
        uint8_t base;
      } u_k_rightbracket;
      u_k_rightbracket.base = 0;
      u_k_rightbracket.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_rightbracket = u_k_rightbracket.real;
      offset += sizeof(this->k_rightbracket);
      union {
        bool real;
        uint8_t base;
      } u_k_caret;
      u_k_caret.base = 0;
      u_k_caret.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_caret = u_k_caret.real;
      offset += sizeof(this->k_caret);
      union {
        bool real;
        uint8_t base;
      } u_k_underscore;
      u_k_underscore.base = 0;
      u_k_underscore.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_underscore = u_k_underscore.real;
      offset += sizeof(this->k_underscore);
      union {
        bool real;
        uint8_t base;
      } u_k_backquote;
      u_k_backquote.base = 0;
      u_k_backquote.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_backquote = u_k_backquote.real;
      offset += sizeof(this->k_backquote);
      union {
        bool real;
        uint8_t base;
      } u_k_exclaim;
      u_k_exclaim.base = 0;
      u_k_exclaim.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_exclaim = u_k_exclaim.real;
      offset += sizeof(this->k_exclaim);
      union {
        bool real;
        uint8_t base;
      } u_k_quotedbl;
      u_k_quotedbl.base = 0;
      u_k_quotedbl.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_quotedbl = u_k_quotedbl.real;
      offset += sizeof(this->k_quotedbl);
      union {
        bool real;
        uint8_t base;
      } u_k_hash;
      u_k_hash.base = 0;
      u_k_hash.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_hash = u_k_hash.real;
      offset += sizeof(this->k_hash);
      union {
        bool real;
        uint8_t base;
      } u_k_dollar;
      u_k_dollar.base = 0;
      u_k_dollar.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_dollar = u_k_dollar.real;
      offset += sizeof(this->k_dollar);
      union {
        bool real;
        uint8_t base;
      } u_k_ampersand;
      u_k_ampersand.base = 0;
      u_k_ampersand.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_ampersand = u_k_ampersand.real;
      offset += sizeof(this->k_ampersand);
      union {
        bool real;
        uint8_t base;
      } u_k_quote;
      u_k_quote.base = 0;
      u_k_quote.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_quote = u_k_quote.real;
      offset += sizeof(this->k_quote);
      union {
        bool real;
        uint8_t base;
      } u_k_leftparen;
      u_k_leftparen.base = 0;
      u_k_leftparen.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_leftparen = u_k_leftparen.real;
      offset += sizeof(this->k_leftparen);
      union {
        bool real;
        uint8_t base;
      } u_k_rightparen;
      u_k_rightparen.base = 0;
      u_k_rightparen.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_rightparen = u_k_rightparen.real;
      offset += sizeof(this->k_rightparen);
      union {
        bool real;
        uint8_t base;
      } u_k_asterisk;
      u_k_asterisk.base = 0;
      u_k_asterisk.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_asterisk = u_k_asterisk.real;
      offset += sizeof(this->k_asterisk);
      union {
        bool real;
        uint8_t base;
      } u_k_plus;
      u_k_plus.base = 0;
      u_k_plus.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_plus = u_k_plus.real;
      offset += sizeof(this->k_plus);
      union {
        bool real;
        uint8_t base;
      } u_k_comma;
      u_k_comma.base = 0;
      u_k_comma.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_comma = u_k_comma.real;
      offset += sizeof(this->k_comma);
      union {
        bool real;
        uint8_t base;
      } u_k_minus;
      u_k_minus.base = 0;
      u_k_minus.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_minus = u_k_minus.real;
      offset += sizeof(this->k_minus);
      union {
        bool real;
        uint8_t base;
      } u_k_period;
      u_k_period.base = 0;
      u_k_period.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_period = u_k_period.real;
      offset += sizeof(this->k_period);
      union {
        bool real;
        uint8_t base;
      } u_k_slash;
      u_k_slash.base = 0;
      u_k_slash.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_slash = u_k_slash.real;
      offset += sizeof(this->k_slash);
      union {
        bool real;
        uint8_t base;
      } u_k_a;
      u_k_a.base = 0;
      u_k_a.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_a = u_k_a.real;
      offset += sizeof(this->k_a);
      union {
        bool real;
        uint8_t base;
      } u_k_b;
      u_k_b.base = 0;
      u_k_b.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_b = u_k_b.real;
      offset += sizeof(this->k_b);
      union {
        bool real;
        uint8_t base;
      } u_k_c;
      u_k_c.base = 0;
      u_k_c.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_c = u_k_c.real;
      offset += sizeof(this->k_c);
      union {
        bool real;
        uint8_t base;
      } u_k_d;
      u_k_d.base = 0;
      u_k_d.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_d = u_k_d.real;
      offset += sizeof(this->k_d);
      union {
        bool real;
        uint8_t base;
      } u_k_e;
      u_k_e.base = 0;
      u_k_e.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_e = u_k_e.real;
      offset += sizeof(this->k_e);
      union {
        bool real;
        uint8_t base;
      } u_k_f;
      u_k_f.base = 0;
      u_k_f.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f = u_k_f.real;
      offset += sizeof(this->k_f);
      union {
        bool real;
        uint8_t base;
      } u_k_g;
      u_k_g.base = 0;
      u_k_g.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_g = u_k_g.real;
      offset += sizeof(this->k_g);
      union {
        bool real;
        uint8_t base;
      } u_k_h;
      u_k_h.base = 0;
      u_k_h.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_h = u_k_h.real;
      offset += sizeof(this->k_h);
      union {
        bool real;
        uint8_t base;
      } u_k_i;
      u_k_i.base = 0;
      u_k_i.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_i = u_k_i.real;
      offset += sizeof(this->k_i);
      union {
        bool real;
        uint8_t base;
      } u_k_j;
      u_k_j.base = 0;
      u_k_j.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_j = u_k_j.real;
      offset += sizeof(this->k_j);
      union {
        bool real;
        uint8_t base;
      } u_k_k;
      u_k_k.base = 0;
      u_k_k.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_k = u_k_k.real;
      offset += sizeof(this->k_k);
      union {
        bool real;
        uint8_t base;
      } u_k_l;
      u_k_l.base = 0;
      u_k_l.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_l = u_k_l.real;
      offset += sizeof(this->k_l);
      union {
        bool real;
        uint8_t base;
      } u_k_m;
      u_k_m.base = 0;
      u_k_m.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_m = u_k_m.real;
      offset += sizeof(this->k_m);
      union {
        bool real;
        uint8_t base;
      } u_k_n;
      u_k_n.base = 0;
      u_k_n.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_n = u_k_n.real;
      offset += sizeof(this->k_n);
      union {
        bool real;
        uint8_t base;
      } u_k_o;
      u_k_o.base = 0;
      u_k_o.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_o = u_k_o.real;
      offset += sizeof(this->k_o);
      union {
        bool real;
        uint8_t base;
      } u_k_p;
      u_k_p.base = 0;
      u_k_p.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_p = u_k_p.real;
      offset += sizeof(this->k_p);
      union {
        bool real;
        uint8_t base;
      } u_k_q;
      u_k_q.base = 0;
      u_k_q.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_q = u_k_q.real;
      offset += sizeof(this->k_q);
      union {
        bool real;
        uint8_t base;
      } u_k_r;
      u_k_r.base = 0;
      u_k_r.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_r = u_k_r.real;
      offset += sizeof(this->k_r);
      union {
        bool real;
        uint8_t base;
      } u_k_s;
      u_k_s.base = 0;
      u_k_s.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_s = u_k_s.real;
      offset += sizeof(this->k_s);
      union {
        bool real;
        uint8_t base;
      } u_k_t;
      u_k_t.base = 0;
      u_k_t.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_t = u_k_t.real;
      offset += sizeof(this->k_t);
      union {
        bool real;
        uint8_t base;
      } u_k_u;
      u_k_u.base = 0;
      u_k_u.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_u = u_k_u.real;
      offset += sizeof(this->k_u);
      union {
        bool real;
        uint8_t base;
      } u_k_v;
      u_k_v.base = 0;
      u_k_v.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_v = u_k_v.real;
      offset += sizeof(this->k_v);
      union {
        bool real;
        uint8_t base;
      } u_k_w;
      u_k_w.base = 0;
      u_k_w.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_w = u_k_w.real;
      offset += sizeof(this->k_w);
      union {
        bool real;
        uint8_t base;
      } u_k_x;
      u_k_x.base = 0;
      u_k_x.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_x = u_k_x.real;
      offset += sizeof(this->k_x);
      union {
        bool real;
        uint8_t base;
      } u_k_y;
      u_k_y.base = 0;
      u_k_y.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_y = u_k_y.real;
      offset += sizeof(this->k_y);
      union {
        bool real;
        uint8_t base;
      } u_k_z;
      u_k_z.base = 0;
      u_k_z.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_z = u_k_z.real;
      offset += sizeof(this->k_z);
      union {
        bool real;
        uint8_t base;
      } u_k_delete;
      u_k_delete.base = 0;
      u_k_delete.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_delete = u_k_delete.real;
      offset += sizeof(this->k_delete);
      union {
        bool real;
        uint8_t base;
      } u_k_kp0;
      u_k_kp0.base = 0;
      u_k_kp0.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp0 = u_k_kp0.real;
      offset += sizeof(this->k_kp0);
      union {
        bool real;
        uint8_t base;
      } u_k_kp1;
      u_k_kp1.base = 0;
      u_k_kp1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp1 = u_k_kp1.real;
      offset += sizeof(this->k_kp1);
      union {
        bool real;
        uint8_t base;
      } u_k_kp2;
      u_k_kp2.base = 0;
      u_k_kp2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp2 = u_k_kp2.real;
      offset += sizeof(this->k_kp2);
      union {
        bool real;
        uint8_t base;
      } u_k_kp3;
      u_k_kp3.base = 0;
      u_k_kp3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp3 = u_k_kp3.real;
      offset += sizeof(this->k_kp3);
      union {
        bool real;
        uint8_t base;
      } u_k_kp4;
      u_k_kp4.base = 0;
      u_k_kp4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp4 = u_k_kp4.real;
      offset += sizeof(this->k_kp4);
      union {
        bool real;
        uint8_t base;
      } u_k_kp5;
      u_k_kp5.base = 0;
      u_k_kp5.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp5 = u_k_kp5.real;
      offset += sizeof(this->k_kp5);
      union {
        bool real;
        uint8_t base;
      } u_k_kp6;
      u_k_kp6.base = 0;
      u_k_kp6.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp6 = u_k_kp6.real;
      offset += sizeof(this->k_kp6);
      union {
        bool real;
        uint8_t base;
      } u_k_kp7;
      u_k_kp7.base = 0;
      u_k_kp7.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp7 = u_k_kp7.real;
      offset += sizeof(this->k_kp7);
      union {
        bool real;
        uint8_t base;
      } u_k_kp8;
      u_k_kp8.base = 0;
      u_k_kp8.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp8 = u_k_kp8.real;
      offset += sizeof(this->k_kp8);
      union {
        bool real;
        uint8_t base;
      } u_k_kp9;
      u_k_kp9.base = 0;
      u_k_kp9.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp9 = u_k_kp9.real;
      offset += sizeof(this->k_kp9);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_period;
      u_k_kp_period.base = 0;
      u_k_kp_period.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp_period = u_k_kp_period.real;
      offset += sizeof(this->k_kp_period);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_divide;
      u_k_kp_divide.base = 0;
      u_k_kp_divide.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp_divide = u_k_kp_divide.real;
      offset += sizeof(this->k_kp_divide);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_multiply;
      u_k_kp_multiply.base = 0;
      u_k_kp_multiply.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp_multiply = u_k_kp_multiply.real;
      offset += sizeof(this->k_kp_multiply);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_minus;
      u_k_kp_minus.base = 0;
      u_k_kp_minus.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp_minus = u_k_kp_minus.real;
      offset += sizeof(this->k_kp_minus);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_plus;
      u_k_kp_plus.base = 0;
      u_k_kp_plus.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp_plus = u_k_kp_plus.real;
      offset += sizeof(this->k_kp_plus);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_enter;
      u_k_kp_enter.base = 0;
      u_k_kp_enter.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp_enter = u_k_kp_enter.real;
      offset += sizeof(this->k_kp_enter);
      union {
        bool real;
        uint8_t base;
      } u_k_kp_equals;
      u_k_kp_equals.base = 0;
      u_k_kp_equals.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_kp_equals = u_k_kp_equals.real;
      offset += sizeof(this->k_kp_equals);
      union {
        bool real;
        uint8_t base;
      } u_k_f1;
      u_k_f1.base = 0;
      u_k_f1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f1 = u_k_f1.real;
      offset += sizeof(this->k_f1);
      union {
        bool real;
        uint8_t base;
      } u_k_f2;
      u_k_f2.base = 0;
      u_k_f2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f2 = u_k_f2.real;
      offset += sizeof(this->k_f2);
      union {
        bool real;
        uint8_t base;
      } u_k_f3;
      u_k_f3.base = 0;
      u_k_f3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f3 = u_k_f3.real;
      offset += sizeof(this->k_f3);
      union {
        bool real;
        uint8_t base;
      } u_k_f4;
      u_k_f4.base = 0;
      u_k_f4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f4 = u_k_f4.real;
      offset += sizeof(this->k_f4);
      union {
        bool real;
        uint8_t base;
      } u_k_f5;
      u_k_f5.base = 0;
      u_k_f5.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f5 = u_k_f5.real;
      offset += sizeof(this->k_f5);
      union {
        bool real;
        uint8_t base;
      } u_k_f6;
      u_k_f6.base = 0;
      u_k_f6.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f6 = u_k_f6.real;
      offset += sizeof(this->k_f6);
      union {
        bool real;
        uint8_t base;
      } u_k_f7;
      u_k_f7.base = 0;
      u_k_f7.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f7 = u_k_f7.real;
      offset += sizeof(this->k_f7);
      union {
        bool real;
        uint8_t base;
      } u_k_f8;
      u_k_f8.base = 0;
      u_k_f8.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f8 = u_k_f8.real;
      offset += sizeof(this->k_f8);
      union {
        bool real;
        uint8_t base;
      } u_k_f9;
      u_k_f9.base = 0;
      u_k_f9.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f9 = u_k_f9.real;
      offset += sizeof(this->k_f9);
      union {
        bool real;
        uint8_t base;
      } u_k_f10;
      u_k_f10.base = 0;
      u_k_f10.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f10 = u_k_f10.real;
      offset += sizeof(this->k_f10);
      union {
        bool real;
        uint8_t base;
      } u_k_f11;
      u_k_f11.base = 0;
      u_k_f11.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f11 = u_k_f11.real;
      offset += sizeof(this->k_f11);
      union {
        bool real;
        uint8_t base;
      } u_k_f12;
      u_k_f12.base = 0;
      u_k_f12.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f12 = u_k_f12.real;
      offset += sizeof(this->k_f12);
      union {
        bool real;
        uint8_t base;
      } u_k_f13;
      u_k_f13.base = 0;
      u_k_f13.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f13 = u_k_f13.real;
      offset += sizeof(this->k_f13);
      union {
        bool real;
        uint8_t base;
      } u_k_f14;
      u_k_f14.base = 0;
      u_k_f14.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f14 = u_k_f14.real;
      offset += sizeof(this->k_f14);
      union {
        bool real;
        uint8_t base;
      } u_k_f15;
      u_k_f15.base = 0;
      u_k_f15.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->k_f15 = u_k_f15.real;
      offset += sizeof(this->k_f15);
     return offset;
    }

    const char * getType(){ return "laptop_node/keyboard"; };
    const char * getMD5(){ return "06a024afd9cb75366fdbcdf7bd7d82a6"; };

  };

}
#endif