
trace-cmd reset

trace caller: trace-cmd record -p function -l cpsw_ndo_open
trace callee: trace-cmd record -p function_graph -g cpsw_ndo_open
trace-cmd report
trace-cmd extract




















