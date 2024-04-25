function flag = buildMexCSMF
    flag = 0;
    try
    cfg = coder.config('mex');
    cfg.IntegrityChecks = false;
    cfg.ExtrinsicCalls = false;
    cfg.IntegrityChecks = false;
    cfg.SaturateOnIntegerOverflow = false;
    cfg.ResponsivenessChecks = false;
    cfg.NumberOfCpuThreads = 16;
    
    warning off
    codegen -config cfg curveSweepModifierFast -silent ...
        -args {coder.typeof(10,[inf,3]), coder.typeof(10,[inf,3]), coder.typeof(10,[inf,1]), coder.typeof(10,[4,4,inf])}
        
    warning on    
    flag = 1;
    end
end