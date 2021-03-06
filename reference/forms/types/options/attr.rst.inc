attr
~~~~

**type**: array **default**: Empty array

If you want to add extra attributes to an HTML field representation
you can use the ``attr`` option. It's an associative array with HTML attributes
as keys. This can be useful when you need to set a custom class for some widget::

    $builder->add('body', 'textarea', array(
        'attr' => array('class' => 'tinymce'),
    ));
