#!/bin/bash

while read text; do
    # check if the text contains uppercase letters, lowercase letters, and digits.
    if [[ "$text" =~ [A-Z] && "$text" =~ [a-z] && "$text" =~ [0-9] ]]; then
        # check if the text contains spaces and commas.
        if [[ "$text" =~ [\ ,] ]]; then
            # check if the text starts with an uppercase letter.
            if [[ "${text:0:1}" =~ [A-Z] ]]; then
                # check if the text ends with a single period.
                if [[ "${text: -1}" == "." && "${text: -2}" != ".." ]]; then
                    # check if the text does not contain "and" followed by a comma and any space between them.
                    if ! [[ "$text" =~ [Aa][Nn][Dd],\ *[A-Za-z] ]]; then
                        # check if the text does not contain "np" or "nb".
                        if ! [[ "$text" =~ [Nn][Pp,Bb] ]]; then
                            echo "$text meets the requirements"
                        fi
                    fi
                fi
            fi
        fi
    fi
done

