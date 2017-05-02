#This is meant to be an example that can be edited to suite
# your needs.

_argconfig_comp () {
        local cur prev words cword
	_init_completion || return
	local compargs=""

	opts=$(ARGCONFIG_COMPLETE=1 ${words[*]:0:$cword})
	compfile=$?

	if [ $compfile -eq 2 ]; then
		compopt -o filenames
		compargs="-f"
	fi

	COMPREPLY=( $( compgen $compargs -W "$opts" -- $cur ) )

	return 0
}

complete -F _argconfig_comp program_name
complete -F _argconfig_comp ./program_name
