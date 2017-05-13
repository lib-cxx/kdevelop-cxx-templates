{% load kdev_filters %}
{% include "libcxx_license_header_cxx.txt" %}


{% block include_guard_open %}
#ifndef {% include "libcxx_include_guard_cxx.txt" %}
#define {% include "libcxx_include_guard_cxx.txt" %}
{% endblock include_guard_open %}


{% block includes %}
{% for included_file in included_files %}
#include {{ included_file }}
{% endfor %}
{% endblock includes %}


{% block namespaces_open %}
{% include "libcxx_namespace_open_cxx.txt" %}
{% endblock namespaces_open %}


{% block forward_declarations %}
{% endblock forward_declarations %}


/// \brief Class {{ name }}
{% block class_declaration_open %}
class {{ name }}{% if base_classes %} :{% for base in base_classes %} {{ base.inheritanceMode }} {{ base.baseType }}{% if not forloop.last %},{% endif %}{% endfor %}{% endif %}
{
{% endblock class_declaration_open %}

{% block class_body %}
{% if private_members %}
private:
    {% for member in private_members %}
    /// \brief {{ member.name }}
    {{ member.type }} {{ member.name }};
    {% endfor %}
{% endif %}
{% if protected_members %}
protected:
    {% for member in protected_members %}
    /// \brief {{ member.name }}
    {{ member.type }} {{ member.name }};
    {% endfor %}
{% endif %}
{% if public_members %}
public:
    {% for member in public_members %}
    /// \brief {{ member.name }}
    {{ member.type }} {{ member.name }};
    {% endfor %}
{% endif %}
{% if private_functions %}
private:
    {% for method in private_functions %}
    {% include "libcxx_method_declaration_cxx.txt" %}
    {% endfor %}
{% endif %}
{% if protected_functions %}
protected:
    {% for method in protected_functions %}
    {% include "libcxx_method_declaration_cxx.txt" %}
    {% endfor %}
{% endif %}
{% if public_functions %}
public:
    {% for method in public_functions %}
    {% include "libcxx_method_declaration_cxx.txt" %}
    {% endfor %}
{% endif %}
{% endblock class_body %}
{% block class_bottom %}
{% endblock %}
{% block class_declaration_close %}
};
{% endblock %}

{% block outside_class %}
{% endblock %}

{% block namespaces_close %}
{% include "libcxx_namespace_close_cxx.txt" %}
{% endblock namespaces_close %}

{% block outside_namespace %}
{% endblock %}


{% block include_guard_close %}
#endif // {% include "libcxx_include_guard_cxx.txt" %}
{% endblock include_guard_close %}
