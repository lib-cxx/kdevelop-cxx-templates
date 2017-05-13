{% load kdev_filters %}
{% include "libcxx_license_header_cxx.txt" %}


{% block includes %}
#include "{{ output_file_header }}"
{% endblock includes %}


{% block namespaces_use %}
{% include "libcxx_namespace_use_cxx.txt" %}
{% endblock namespaces_use %}


{% block extra_declarations %}
{% endblock extra_declarations %}


{% block extra_definitions %}
{% endblock extra_definitions %}


{% block function_definitions %}
{% for method in functions %}
{% include "libcxx_method_definition_cxx.txt" %}
{


}


{% endfor %}

{% endblock function_definitions %}


{% block bottom %}
{% endblock %}
