function [g, J] = string(Shapes,q,varargin)
    
    assert(numel(q) == Shapes.NJoint,['Dimension of joint inconstistent ',...
            'with POD matrix. Please check your input dimensions dim(q).']);
    
    % ensures robustness for near-zero singularities in some PCC models
    q = q(:) + 1e-12;
    % if isempty(varargin)
    % [g, J] = computeForwardKinematicsFast_mex(q,q*0,... % states
    %     Shapes.beamsolver.SpaceStep,...         % spatial steps
    %     Shapes.beamsolver.g0(1:3,4),...         % position zero
    %     Shapes.beamsolver.g0(1:3,1:3),...       % phi zeroclc
    %     Shapes.beamsolver.Xi0Eval,...    % intrinsic strain vector
    %     Shapes.beamsolver.ThetaEval,...  % evaluated Theta matrix
    %     Shapes.beamsolver.DofMap);
    % else

    [g, J] = computeForwardKinematicsGaussFast_mex(q,q*0,... % states
        Shapes.beamsolver.g0(1:3,4),...         % position zero
        Shapes.beamsolver.g0(1:3,1:3),...       % phi zeroclc
        Shapes.beamsolver.evalLocal.Xi0,...    % intrinsic strain vector
        Shapes.beamsolver.evalLocal.Theta,...  % evaluated Theta matrix
        Shapes.beamsolver.DofMap,...           % dof to strain mapping
        Shapes.beamsolver.evalLocal.weights,...
        Shapes.beamsolver.evalLocal.points);  % gauss weights    
    % end

    if nargout > 1
        % transform jacobian from local into global (static) frame
        [J] = computeFrameChangeFast(q*0,g,J,J*0);
    end
end