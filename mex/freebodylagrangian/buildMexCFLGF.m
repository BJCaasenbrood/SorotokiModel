function flag = buildMexCFLGF
    flag = 0;
    try
    cfg = coder.config('mex');
    cfg.IntegrityChecks = false;
    cfg.ExtrinsicCalls = false;
    cfg.IntegrityChecks = false;
    cfg.SaturateOnIntegerOverflow = false;
    cfg.ResponsivenessChecks = false;
    cfg.NumberOfCpuThreads = 16;

    codegen -config cfg computeFreeLagrangianGaussFast.m ...
        -args {coder.typeof(10,[inf,1]), coder.typeof(10,[inf,1]), coder.typeof(10,[4,4,inf,inf]), coder.typeof(10,[6,inf,inf,inf]), coder.typeof(10,[6,inf,inf,inf]), coder.typeof(10,[inf,inf,inf,inf]), coder.typeof(10,[6,inf]), coder.typeof(10,[6,inf]), coder.typeof(10,[6,6,inf,inf]), coder.typeof(10,[6,6,inf,inf]), coder.typeof(10,[5,1]), coder.typeof(10,[3,1]), coder.typeof(10,[inf,inf]), coder.typeof(10,[inf,inf])}
    
    warning on    
    flag = 1;
    end
end